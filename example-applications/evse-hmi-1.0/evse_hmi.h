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

#ifndef EVSE_HMI_H
#define EVSE_HMI_H

#include <QMainWindow>

namespace Ui {
class evse_hmi;
}

class evse_hmi : public QMainWindow
{
    Q_OBJECT

public:
    explicit evse_hmi(QWidget *parent = 0);
    ~evse_hmi();

private:
    Ui::evse_hmi *ui;
    int timerId;
    double percentComplete;
    bool start;

    int milliseconds;
    int seconds;
    int minutes;
    int hours;

    int millisecondsElapsed;
    int secondsElapsed;
    int minutesElapsed;

private slots:

    void on_ContinueButton_clicked();

    void on_ExitButton_clicked();

    void on_ChargingMode1_clicked();

    void on_ChargingMode2_clicked();

    void on_ChargingMode3_clicked();

    void on_ChargingMode4_clicked();

    void on_Page1Home_clicked();

    void on_OkButton_clicked();

    void on_Page2Home_clicked();

    void on_BeginChargeButton_clicked();

    void on_EndChargeButton_clicked();

    void resetProgressBar();

protected:
    void timerEvent(QTimerEvent *event);

};

#endif // EVSE_HMI_H
