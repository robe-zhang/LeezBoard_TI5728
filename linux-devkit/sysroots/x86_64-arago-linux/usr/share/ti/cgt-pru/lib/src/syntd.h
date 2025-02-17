/****************************************************************************/
/*  syntd.h          v2.2.1                                                 */
/*                                                                          */
/* Copyright (c) 1997-2017 Texas Instruments Incorporated                   */
/* http://www.ti.com/                                                       */
/*                                                                          */
/*  Redistribution and  use in source  and binary forms, with  or without   */
/*  modification,  are permitted provided  that the  following conditions   */
/*  are met:                                                                */
/*                                                                          */
/*     Redistributions  of source  code must  retain the  above copyright   */
/*     notice, this list of conditions and the following disclaimer.        */
/*                                                                          */
/*     Redistributions in binary form  must reproduce the above copyright   */
/*     notice, this  list of conditions  and the following  disclaimer in   */
/*     the  documentation  and/or   other  materials  provided  with  the   */
/*     distribution.                                                        */
/*                                                                          */
/*     Neither the  name of Texas Instruments Incorporated  nor the names   */
/*     of its  contributors may  be used to  endorse or  promote products   */
/*     derived  from   this  software  without   specific  prior  written   */
/*     permission.                                                          */
/*                                                                          */
/*  THIS SOFTWARE  IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS   */
/*  "AS IS"  AND ANY  EXPRESS OR IMPLIED  WARRANTIES, INCLUDING,  BUT NOT   */
/*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR   */
/*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT   */
/*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   */
/*  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL  DAMAGES  (INCLUDING, BUT  NOT   */
/*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   */
/*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY   */
/*  THEORY OF  LIABILITY, WHETHER IN CONTRACT, STRICT  LIABILITY, OR TORT   */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE   */
/*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    */
/*                                                                          */
/****************************************************************************/

#ifndef __syntd__
#define __syntd__


#define EXPONENT_TYPE int

#define CNST(x) (x) /*  constants within statements */
#define TSNC
#define KNST(x) x   /*  constants within tables     */
#define TSNK

#include "numconst.h" /*  NUMerical CONSTants used by some definitions below */


#define CPYF(dst,right) dst=(right)

#define NEGF(right) (-(right))
#define ABSF(right) (LSSF(right,ZERO) ? NEGF(right) : (right))
#define SQRF(right) ((right) * (right))
#define INVF(right) DIVF(ONE,right)

#define ADDF(left,right) ((left)+(right))
#define SUBF(left,right) ((left)-(right))
#define MPYF(left,right) ((left)*(right))
#define DIVF(left,right) ((left)/(right))

#define NEGF2(dst,right) dst=(-(right))
#define ABSF2(dst,right) dst=(LSSF(right,ZERO)?NEGF(right):(right))
#define SQRF2(dst,right) dst=(right)*(right)
#define INVF2(dst,right) dst=INVF(right)

#define ADDF3(dst,left,right) dst=(left)+(right)
#define SUBF3(dst,left,right) dst=(left)-(right)
#define MPYF3(dst,left,right) dst=(left)*(right)
#define DIVF3(dst,left,right) dst=(left)/(right)

#define NEGF1(right) (right)=-(right)
#define ABSF1(right) if LSSF(right,ZERO) NEGF1(right)
#define SQRF1(right) (right)*=(right)
#define INVF1(right) (right)=INVF(right)

#define ADDF2(left,right) (left)+=(right)
#define SUBF2(left,right) (left)-=(right)
#define RSBF2(left,right) (left) =(right)-(left)
#define MPYF2(left,right) (left)*=(right)
#define DIVF2(left,right) (left)/=(right)

#define CMPF(left,right) ((left)<(right)?-1:((left)!=(right)))
#define CMPF3(dst,left,right) dst=CMPF(left,right)

#define EQLF(left,right) ((left)==(right))
#define NEQF(left,right) ((left)!=(right))
#define LEQF(left,right) ((left)<=(right))
#define GEQF(left,right) ((left)>=(right))
#define GTRF(left,right) ((left)>(right))
#define LSSF(left,right) ((left)<(right))

#define EQZF(left) EQLF(left,ZERO)
#define NEZF(left) NEQF(left,ZERO)
#define LEZF(left) LEQF(left,ZERO)
#define GEZF(left) GEQF(left,ZERO)
#define GTZF(left) GTRF(left,ZERO)
#define LSZF(left) LSSF(left,ZERO)




#define RIPF(x,f,e) f=FREXPF((x),&e)

#define SCLF(f,e)            LDEXPF((f),(e))
#define SCLF2(f,e)       f = LDEXPF((f),(e))
#define SCLF3(dst,f,e) dst = LDEXPF((f),(e))

#define FIXFC(x) ((char)(x))
#define FLTCF(x) ((REAL)(x))

#define FIXFB(x) ((unsigned char)(x))
#define FLTBF(x) ((REAL)(x))

#define FIXFSI(x) ((short)(x))
#define FLTSIF(x) ((REAL)(x)) 

#define FIXFUS(x) ((unsigned short)(x))
#define FLTUSF(x) ((REAL)(x))

#define FIXFI(x) ((int)(x))
#define FLTIF(x) ((REAL)(x))

#define FIXFU(x) ((unsigned)(x))
#define FLTUF(x) ((REAL)(x))

#define FIXFLI(x) ((long)(x))
#define FLTLIF(x) ((REAL)(x))

#define FIXFUL(x) ((unsigned long)(x))
#define FLTULF(x) ((REAL)(x))

#define FIXFLLI(x) ((long long)(x))
#define FLTLLIF(x) ((REAL)(x))

#define FIXFULL(x) ((unsigned long long)(x))
#define FLTULLF(x) ((REAL)(x))


#ifndef FLT_FIX_Faster_Than_MODF
   #error "target props .h file must be included before REAL syntax .h file"
#endif
#if (FLT_FIX_Faster_Than_MODF)
   #define TNCF(x) (FLTIF(FIXFI(x)))

   #define RNDF(x) (GEZF(x)? \
                    FLTIF(FIXFI((ADDF((x),HALF)))) : \
                    FLTIF(FIXFI((SUBF((x),HALF)))))

   #define FLRF(x) (GEZF(x) ? \
                    (FLTIF(FIXFI(x))) : \
                     (EQLF(x,FLTIF(FIXFI(x))) ? \
                      x : \
                      (FLTIF(NEGF(FIXFI(ADDF(NEGF(x),ONE)))))))

   #define CEIF(x) (LEZF(x) ? \
                    (FLTIF(FIXFI(x))) : \
                     (EQLF(x,FLTIF(FIXFI(x))) ? \
                      x : \
                      (FLTIF(NEGF(FIXFI(SUBF(NEGF(x),ONE)))))))

#else /*  call through to general purpose routines */
   #define TNCF(x) (TRUNCF(x))
   #define RNDF(x) (ROUNDF(x))
   #define FLRF(x) (FLOORF(x))
   #define CEIF(x) (CEILF(x))
#endif

#define FIXFI1(x) x=FIXFI(x)
#define FLTIF1(x) x=FLTIF(x)
#define FIXFU1(x) x=FIXFU(x)
#define FLTUF1(x) x=FLTUF(x)

#define TNCF1(x) x=TNCF(x)
#define RNDF1(x) x=RNDF(x)
#define FLRF1(x) x=FLRF(x)
#define CEIF1(x) x=CEIF(x)

#define FIXFI2(dst,right) dst=FIXFI(right)
#define FLTIF2(dst,right) dst=FLTIF(right)
#define FIXFU2(dst,right) dst=FIXFU(right)
#define FLTUF2(dst,right) dst=FLTUF(right)

#define TNCF2(dst,right) dst=TNCF(right)
#define RNDF2(dst,right) dst=RNDF(right)
#define FLRF2(dst,right) dst=FLRF(right)
#define CEIF2(dst,right) dst=CEIF(right)


#define REMF(right,left)           (FMODF(right,left))
#define REMF1(right,left)     right=FMODF(right,left)
#define REMF2(dst,right,left) dst  =FMODF(right,left)

#ifdef LEAN
   #define GROWF(x) ((REAL)(x)) /*  grow from LEAN to REAL */
   #define SLIMF(x) ((LEAN)(x)) /*  slim from REAL to LEAN */
#endif


#define POLYF(r,x,K,s) {int i; REAL *p=K;                             \
                        MPYF3(r,x,*p++);                              \
                        for (i=s-1; i>0; i--) MPYF3(r,x,ADDF(r,*p++));}

#define POLYaF(r,x,K,s) {int i; REAL *p=K;                             \
                         MPYF3(r,x,*p++);                              \
                         for (i=s-2; i>0; i--) MPYF3(r,x,ADDF(r,*p++));\
                         ADDF2(r,*p++);}

#define POLYbF(r,x,K,s) {int i; REAL *p=K;                             \
                         ADDF3(r,x,*p++);                              \
                         for (i=s-1; i>0; i--) ADDF3(r,*p++,MPYF(x,r));}

#define SQRTF(x)    sqrt(x)
#define RSQRTF(x)   rsqrt(x)
#define EXPF(x)     exp(x)
#define EXP2F(x)    exp2(x)
#define EXP10F(x)   exp10(x)
#define LOGF(x)     log(x)
#define LOG2F(x)    log2(x)
#define LOG10F(x)   log10(x)
#define POWF(x,y)   pow(x,y)
#define POWIF(x,i)  powi(x,i)
#define SINF(x)     sin(x)
#define COSF(x)     cos(x)
#define TANF(x)     tan(x)
#define COTF(x)     cot(x)
#define ASINF(x)    asin(x)
#define ACOSF(x)    acos(x)
#define ATANF(x)    atan(x)
#define ATAN2F(y,x) atan2(y,x)
#define ACOTF(x)    acot(x)
#define ACOT2F(x,y) acot2(x,y)
#define SINHF(x)    sinh(x)
#define COSHF(x)    cosh(x)
#define TANHF(x)    tanh(x)
#define COTHF(x)    coth(x)
#define ASINHF(x)   asinh(x)
#define ACOSHF(x)   acosh(x)
#define ATANHF(x)   atanh(x)
#define ACOTHF(x)   acoth(x)

#define CEILF(x)    ceil(x)
#define FLOORF(x)   floor(x)
#define TRUNCF(x)   _trunc(x)
#define ROUNDF(x)   _nround(x)

#define FABSF(x)    fabs(x)

#define LDEXPF(x,n)   ldexp(x,n)
#define FREXPF(x,exp) frexp(x,exp)
#define MODFF(x,ip)   modf(x,ip)
#define FMODF(x,y)    fmod(x,y)

#define FRCMPYF_DIV(x, y) __TI_frcmpyd_div(x, y)

#if (BPREAL == BPbigint)
   #define FRCMPYF(l,r) __TI_frcmpyd(l,r)
   #define FRCDIVF(l,r) __TI_frcdivd(l,r)
#elif (BPREAL == (BPbigint*2))
   #define RENORMF(x) __TI_renormd(x)
   #define FRCADDF(lx,lf,rx,rf) __TI_frcaddd(lx,lf,rx,rf)
   #define FRCMPYF(p,l,r) __TI_frcmpyd(p,l,r)
   #define FRCDIVF(q,l,r) __TI_frcdivd(q,l,r)
#else
   #error "IEEE lowest-level support routines NYI for this size REAL"
#endif
#endif /* __syntd__*/
