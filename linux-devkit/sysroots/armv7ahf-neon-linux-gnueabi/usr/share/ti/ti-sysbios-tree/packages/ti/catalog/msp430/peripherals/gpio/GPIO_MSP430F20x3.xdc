/*
 * Copyright (c) 2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

import ti.catalog.msp430.peripherals.communication.USI as USI;
import ti.catalog.msp430.peripherals.adc.SD16_A as SD16_A;

/*!
 *  ======== GPIO for MSP430F20x3 ========
 *  MSP430 General Purpose Input Output Ports
 */
metaonly module GPIO_MSP430F20x3 inherits IGPIO {
    /*!
     *  ======== create ========
     *  Create an instance of this peripheral.
     */
    create(USI.Instance usi, SD16_A.Instance sd16_A);

instance:
    /*! @_nodoc */
    config USI.Instance usi;

    /*! @_nodoc */
    config SD16_A.Instance sd16_A;

   /*! Define an array to describe all device pins. The 1st dimension
    *  denotes the port, the second the pin on that port. On an
    *  MSP430F20x3 device, there are 8 + 2 = 10 pins total.
    */

    /* TODO: This here should really be a module-wide feature, rather than an instance feature,
     * however due to limitations in XDCtools 3.21.0.0 the data is located here */
    readonly config DevicePin_t devicePins[2][8];

    /*! Implementation of Device Pin Functional Configuration */
    override config DevicePinFunctionSetting_t devicePinSetting[2][8];

    /*! Determine if each Register needs to be forced set or not */
    readonly config ForceSetDefaultRegister_t forceSetDefaultRegister[] =
    [
        { register : "P1OUT" , regForceSet : true  },
        { register : "P1SEL" , regForceSet : false },
        { register : "P1DIR" , regForceSet : true  },
        { register : "P1REN" , regForceSet : false },
        { register : "P1IES" , regForceSet : true },
        { register : "P1IFG" , regForceSet : true },
        { register : "P1IE"  , regForceSet : false },
        { register : "P2OUT" , regForceSet : true  },
        { register : "P2SEL" , regForceSet : false },
        { register : "P2DIR" , regForceSet : true  },
        { register : "P2REN" , regForceSet : false },
        { register : "P2IES" , regForceSet : true },
        { register : "P2IFG" , regForceSet : true },
        { register : "P2IE"  , regForceSet : false }
    ];

    /*
     *  GPIO Digital I/O Registers
     *
     *  One GIPO instance defines the configuration of an entire,
     *  8-bit wide digital I/O port.
     */

    /*! Port 1 Output Register */
    config GpioBits8PxOut_t P1OUT = {
        Bit0        : BIT0_OFF,
        Bit1        : BIT1_OFF,
        Bit2        : BIT2_OFF,
        Bit3        : BIT3_OFF,
        Bit4        : BIT4_OFF,
        Bit5        : BIT5_OFF,
        Bit6        : BIT6_OFF,
        Bit7        : BIT7_OFF
    };

    /*! Port 1 Port Select Register */
    config GpioBits8PxSel_t P1SEL = {
        Bit0        : BIT0_OFF,
        Bit1        : BIT1_OFF,
        Bit2        : BIT2_OFF,
        Bit3        : BIT3_OFF,
        Bit4        : BIT4_OFF,
        Bit5        : BIT5_OFF,
        Bit6        : BIT6_OFF,
        Bit7        : BIT7_OFF
    };

    /*! Port 1 Direction Register */
    config GpioBits8PxDir_t P1DIR = {
        Bit0        : BIT0_OFF,
        Bit1        : BIT1_OFF,
        Bit2        : BIT2_OFF,
        Bit3        : BIT3_OFF,
        Bit4        : BIT4_OFF,
        Bit5        : BIT5_OFF,
        Bit6        : BIT6_OFF,
        Bit7        : BIT7_OFF
    };

    /*! Port 1 Resistor Enable Register */
    config GpioBits8PxRen_t P1REN = {
        Bit0        : BIT0_OFF,
        Bit1        : BIT1_OFF,
        Bit2        : BIT2_OFF,
        Bit3        : BIT3_OFF,
        Bit4        : BIT4_OFF,
        Bit5        : BIT5_OFF,
        Bit6        : BIT6_OFF,
        Bit7        : BIT7_OFF
    };

    /*! Port 2 Output Register */
    config GpioBits8PxOut_t P2OUT = {
        Bit0        : BIT0_OFF,
        Bit1        : BIT1_OFF,
        Bit2        : BIT2_OFF,
        Bit3        : BIT3_OFF,
        Bit4        : BIT4_OFF,
        Bit5        : BIT5_OFF,
        Bit6        : BIT6_OFF,
        Bit7        : BIT7_OFF
    };

    /*! Port 2 Port Select Register */
    config GpioBits8PxSel_t P2SEL = {
        Bit0        : BIT0_OFF,
        Bit1        : BIT1_OFF,
        Bit2        : BIT2_OFF,
        Bit3        : BIT3_OFF,
        Bit4        : BIT4_OFF,
        Bit5        : BIT5_OFF,
        Bit6        : BIT6,         /* POR default for all 2xx devices */
        Bit7        : BIT7          /* POR default for all 2xx devices */
    };

    /*! Port 2 Direction Register */
    config GpioBits8PxDir_t P2DIR = {
        Bit0        : BIT0_OFF,
        Bit1        : BIT1_OFF,
        Bit2        : BIT2_OFF,
        Bit3        : BIT3_OFF,
        Bit4        : BIT4_OFF,
        Bit5        : BIT5_OFF,
        Bit6        : BIT6_OFF,
        Bit7        : BIT7_OFF
    };

    /*! Port 2 Resistor Enable Register */
    config GpioBits8PxRen_t P2REN = {
        Bit0        : BIT0_OFF,
        Bit1        : BIT1_OFF,
        Bit2        : BIT2_OFF,
        Bit3        : BIT3_OFF,
        Bit4        : BIT4_OFF,
        Bit5        : BIT5_OFF,
        Bit6        : BIT6_OFF,
        Bit7        : BIT7_OFF
    };
}
