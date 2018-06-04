/*

 Copyright (c) 2018, Kristian Møllenborg - kristian@mollenborg.dk
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 * Neither the name of Kristian Møllenborg nor the
 names of its contributors may be used to endorse or promote products
 derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL KRISTIAN MØLLENBORG BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cableBrain.h"
#include "uri.h"
#include "config.h"
#include "aboutelektro.h"
#include "properties.h"
#include <thread>
#include <qtimer.h>
#include <qdir.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:




    void on_LE_ikmax_textChanged(const QString &arg1);

    void on_CBkabelETmateriale_currentTextChanged(const QString &arg1);

    void on_CBkabelETkvadrat_currentTextChanged(const QString &arg1);

    void loadCableOne();

    void loadCableTwo();

    void kabelETingenX(bool arg1);

    void kabelTOingenX(bool arg1);

    void beregn();

    void setDiagramLabels();

    void setLabelCableOne();

    void setLabelCableTwo();

     void setLabelCableThree();

    void setLabelCableOnePe();

    void setLabelCableTwoPe();

     void setLabelCableThreePe();

    void on_CBkabelETconductors_currentTextChanged();

    void on_CBkabelETpenOplagt_currentTextChanged(const QString &arg1);

    void on_CBkabelETpenMateriale_currentTextChanged(const QString &arg1);

    void on_CBkabelETpenKvadrat_currentTextChanged();

    void on_LEkabelETlangde_textChanged();

    void on_LEkabelETantal_textChanged();



    void on_CBkabelETantal_currentTextChanged();

    void on_CBkabelETpenAntal_currentTextChanged();

    void on_LE_ikmin_textChanged(const QString &ikmin);

    void on_CBkabelTOmateriale_currentTextChanged(const QString &arg1);

    void on_CBkabelTOkvadrat_currentTextChanged(const QString &arg1);

    void on_CBkabelTOconductors_currentTextChanged();



    void on_CBkabelTOpenOplagt_currentTextChanged(const QString &arg1);

    void on_CBkabelTOpenMateriale_currentTextChanged(const QString &arg1);

    void on_CBkabelTOpenKvadrat_currentTextChanged();

    void on_CBkabelTOantal_currentTextChanged();

    void on_LEkabelTOlangde_textChanged();

    void on_CBkabelTREmateriale_currentTextChanged(const QString &arg1);
    
    void on_CBkabelTREkvadrat_currentTextChanged(const QString &arg1);

    void on_CBkabelTREconductors_currentTextChanged();

    void on_CBkabelTREantal_currentTextChanged();

    void on_LEkabelTRElangde_textChanged();

    void on_CBkabelTREpenOplagt_currentTextChanged(const QString &arg1);

    void on_CBkabelTREpenMateriale_currentTextChanged(const QString &arg1);



    void on_CBkabelTREpenKvadrat_currentTextChanged();

    void on_actionOm_elektro3_triggered();

    void on_actionIndstillinger_triggered();

    void timertick();

    void loadConfig();

private:
    Ui::MainWindow *ui;
    aboutElektro about;
    properties indstillinger;

    QString version = "0.1";
    cableBrain kabelET, kabelTO, kabelTRE;
    uri uri;
    double defaultX;
    double IkmaxA, IkmaxB, IkmaxC, IkmaxD;
    double IkminA, IkminB, IkminC, IkminD;
    void test();
    bool propDiaOpen = false;


};

#endif // MAINWINDOW_H
