/*
 * Copyright (c) 2013, Texas Instruments Incorporated - http://www.ti.com/
 *   All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *      * Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *      * Neither the name of Texas Instruments Incorporated nor the
 *        names of its contributors may be used to endorse or promote products
 *        derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * \file tomp_qmss.h
 *       API to access the QMSS sub-system. Wraps the QMSS LLD APIs
 */

#ifndef _TOMP_QUEUES_H_
#define _TOMP_QUEUES_H_

#include <stdbool.h>
#include <stdint.h>

#include "tomp_defs.h"
#include "tomp_log.h"
#include "tomp_util.h"

#if TOMP_DEVICE_HAS_HW_QUEUES
#include "tomp_qmss.h"
#else

typedef struct _sw_queue_item
{
   void *item;
   struct _sw_queue_item *next;
} sw_queue_item;

typedef struct 
{
   sw_queue_item *head;
   sw_queue_item *tail;
   uint32_t lock;
   volatile uint32_t empty;
} sw_queue;

#define TOMP_MAX_SW_QUEUES 24
extern sw_queue_item queue_items[TOMP_EVENT_NUM];
extern sw_queue queues[TOMP_MAX_SW_QUEUES];
extern uint32_t queue_count;

static inline void queue_mutex_lock(sw_queue *Q)
{
   tomp_mutex_lock(Q->lock);
   // flush_acquire(Q, sizeof(Queue));
}

static inline void queue_mutex_unlock(sw_queue *Q)
{
   // flush_release(Q, sizeof(Queue));
   tomp_mutex_unlock(Q->lock);
}

static inline sw_queue_item* queuePop(sw_queue *Q)
{
   sw_queue_item *item = NULL;

   if (!Q->empty)
   {
      queue_mutex_lock(Q);

      if (!Q->empty)
      {
         item = Q->head;
         if (Q->head == Q->tail)
         {
            Q->head = Q->tail = NULL;
            Q->empty = 1;
         }
         else
         {
            Q->head = Q->head->next;
         }
      }

      queue_mutex_unlock(Q);
   }

   return item;
}

static inline void queuePushDesc(sw_queue *Q, sw_queue_item *item)
{
   queue_mutex_lock(Q);

   if (Q->tail == NULL)
   {
      Q->head = Q->tail = item;
      Q->empty = 0;
   }
   else
   {
      Q->tail->next = item;
      Q->tail = item;
   }

   queue_mutex_unlock(Q);
}

static inline void queuePush(sw_queue *Q, sw_queue_item *item)
{
   queue_mutex_lock(Q);

   if (Q->head == NULL)
   {
      Q->head = Q->tail = item;
      Q->empty = 0;
   }
   else
   {
      item->next = Q->head;
      Q->head = item;
   }

   queue_mutex_unlock(Q);
}

static inline sw_queue *queueAlloc(uint32_t idx)
{
   return &queues[idx];
}

static inline void queueAssignLock(sw_queue *Q, uint32_t lock)
{
   Q->lock = lock;
}

static inline void queueEmpty(sw_queue *Q)
{
   queue_mutex_lock(Q);

   Q->head = NULL;
   Q->tail = NULL;
   Q->empty = 1;

   queue_mutex_unlock(Q);
}

static inline void queueClose(sw_queue *Q)
{
   return;
}

typedef sw_queue_item *tomp_event_t;
typedef sw_queue *tomp_queue_t;

/* General purpose queues used by OpenMP runtime */
typedef struct
{
    uint32_t     numExplicitTaskQ;
    tomp_queue_t exitQ;
    tomp_queue_t finishQ;
    tomp_queue_t freeDescriptorQ;
    tomp_queue_t implicitTaskQ[TOMP_DEVICE_NUM_CORES];
    tomp_queue_t explicitTaskQ[TOMP_DEVICE_NUM_CORES];
} tomp_Queues;

extern tomp_Queues tomp_queues;

bool tomp_initGlobalNRT (bool memRegionInitialized);
void tomp_exitGlobalNRT (void);
bool tomp_initLocalNRT  (void);

/**
 * Allocate a buffer from the TOMP free queue
 *
 * @return event handle. Use tomp_event_pointer to convert the handle 
 * to a pointer to the event structure
 */
static inline tomp_event_t tomp_eventAlloc(void)
{
    // The popped descriptor may have its size encoded in lower 4 bits.
    // QMSS_DESC_PTR clears these bits out.
    return (tomp_event_t)queuePop(tomp_queues.freeDescriptorQ);
}


/**
 * Allocate a buffer from the TOMP free queue w/ NULL check
 *
 * @param size size requested
 * @param file __FILE__ at call site, for error messages
 * @param line __LINE__ at call site, for error messages
 * @return event handle. Use tomp_event_pointer to convert the handle 
 * to a pointer to the event structure
 */
static inline tomp_event_t tomp_eventAllocChecked(size_t size, 
                                                  const char *file, int line)
{
    #if defined (TOMP_CHECK_LEVEL) && (TOMP_CHECK_LEVEL > 0)
    if (size > TOMP_EVENT_BUF_SIZE)
        tomp_logError(tomp_ErrorKind_EM_ALLOC_SIZE, file, line);
    #endif

    tomp_event_t event = tomp_eventAlloc();
    if (!event)
        tomp_logError(tomp_ErrorKind_NULL_PTR, file, line);

    return event;
}


/**
 * Free a buffer allocated from the TOMP free queue
 *
 * @param event Buffer to be free'd
 */
static inline void tomp_eventFree(tomp_event_t event)
{
    queuePushDesc (tomp_queues.freeDescriptorQ, event);
    return;
}


/**
 * Push an event onto the tail of the specified queue
 *
 * @param qHnd  queue to push the event onto
 * @param event event to be pushed
 */
static inline void tomp_eventPush(tomp_queue_t qHnd, tomp_event_t event)
{
    queuePushDesc (qHnd, event);
}


/**
 * Push an event onto the head of the specified queue
 *
 * @param qHnd  queue to push the event onto
 * @param event event to be pushed
 */
static inline void tomp_eventPushToHead(tomp_queue_t qHnd, tomp_event_t event)
{
    queuePush(qHnd, event);
    return;
}


/**
 * Pop an event from the head of the specified queue
 *
 * @param qHnd  queue to pop the event from
 * @return popped event
 */
static inline tomp_event_t tomp_eventPop(tomp_queue_t qHnd)
{
    // The popped descriptor may have its size encoded in lower 4 bits.
    // QMSS_DESC_PTR clears these bits out.
    return queuePop(qHnd);
}


/**
 * Extract the storage buffer from an event.
 * Since the OpenMP runtime does not need to initialize any fields in the
 * descriptor, the entire descriptor is teh storage buffer
 */
static inline void* tomp_event_pointer(tomp_event_t event)
{
    return event->item;
}

#endif /* TOMP_DEVICE_HAS_HW_QUEUES */
#endif /*  _TOMP_QMSS_H_ */
