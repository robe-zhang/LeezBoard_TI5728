/*
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/


#include "evse_hmi.h"
#include "ui_evse_hmi.h"

#include <QProgressBar>
#include <QTimer>
#include <iostream>


evse_hmi::evse_hmi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::evse_hmi)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    resetProgressBar();
}

evse_hmi::~evse_hmi()
{
    delete ui;
}


/* Page 0 Functions */
void evse_hmi::on_ContinueButton_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(1);
}

void evse_hmi::on_ExitButton_clicked()
{
    qApp -> quit();
}


/* Page 1 Functions */
void evse_hmi::on_ChargingMode1_clicked()
{
      ui -> stackedWidget -> setCurrentIndex(2);
}

void evse_hmi::on_ChargingMode2_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(2);
}

void evse_hmi::on_ChargingMode3_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(2);
}

void evse_hmi::on_ChargingMode4_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(2);
}

void evse_hmi::on_Page1Home_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(0);
}



/* Page 2 Functions*/
void evse_hmi::on_OkButton_clicked()
{
     ui -> stackedWidget -> setCurrentIndex(3);
}


void evse_hmi::on_Page2Home_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(0);
}



/* Page 3 Functions */
void evse_hmi::on_BeginChargeButton_clicked()
{
    /* startTimer function will trigger the timerEvent function to be
       called every 10 milliseconds */
    timerId = startTimer(175);
    start = 1;
}

void evse_hmi::timerEvent(QTimerEvent *event)
{
    if(milliseconds >= 0 && start) {

        /* The accept method is used to satisfy the compiler. If it
         *  is not used the compiler will give the following warning:
         *  "Warning unused event" */
        event -> accept();

        // Remaining charge time calculations
        minutes = (milliseconds % (1000*60*60)) / (1000*60);
        seconds = ((milliseconds % (1000*60*60)) % (1000*60)) / 1000;
        milliseconds = milliseconds - 5000;
        //Hours = Milliseconds / (1000*60*60);

        // Time elapsed calculations
        millisecondsElapsed = millisecondsElapsed + 5000;
        secondsElapsed = ((millisecondsElapsed % (1000*60*60)) % (1000*60)) / 1000;
        minutesElapsed = (millisecondsElapsed % (1000*60*60)) / (1000*60);

        // Percentage charged calculations
        percentComplete = (((double) milliseconds / (double) 3600000))*100;
        percentComplete = 100 - percentComplete;
        ui -> ProgressBar -> setValue(percentComplete);

        // Remaining time and elapsed time screen updates
        char rBuffer[30];
        char eBuffer[30];
        sprintf(rBuffer,"%i:%02i",minutes,seconds);
        sprintf(eBuffer,"%i:%02i",minutesElapsed,secondsElapsed);
        ui -> RemainingTimeLabel -> setStyleSheet("font-size:10pt;font-weight:600; color:#ffffff;border:none;");
        ui -> RemainingTimeLabel->setText(rBuffer);
        ui -> RemainingTimeLabel -> setStyleSheet("font-size:10pt;font-weight:600; color:#ffffff;border:none;");
        ui -> ElapsedTimeLabel->setText(eBuffer);
    }
}

void evse_hmi::on_EndChargeButton_clicked()
{
    /*  Setting the start variable to 0 will stop
     *  the progress bar from updating any further */
    start = 0;
    ui -> stackedWidget -> setCurrentIndex(0);
    resetProgressBar();
}

void evse_hmi::resetProgressBar() {
    //setting start flag to 0
    start = 0;

    //setting progress bar's value attribute to 0
    ui -> ProgressBar -> setValue(0);

    // Initalizing percentComplete variable
    percentComplete = 0;

    // Initializing all variables needed for calculating charge time remaining and elapsed
    milliseconds = 3600000;
    minutes = 0;
    seconds = 0;
    millisecondsElapsed = -10000;
    secondsElapsed = 0;
    minutesElapsed = 0;
    //hours = 0;

    // Resetting remaining time and elapsed time values
    ui -> RemainingTimeLabel -> setStyleSheet("font-size:10pt;font-weight:600; color:#ffffff;border:none;");
    ui -> RemainingTimeLabel->setText("60:00");
    ui -> ElapsedTimeLabel -> setStyleSheet("font-size:10pt;font-weight:600; color:#ffffff;border:none;");
    ui -> ElapsedTimeLabel->setText("0:00");
}



