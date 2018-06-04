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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"


using namespace std;

QStringList crosssectionsCU, crosssectionsAL, crosssectionCon, crosssectionPE;
QStringList material, number;
QStringList conductors;
QStringList PEplacement;




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->labelStatus->setText(version);
    ui->LE_ikmax->setText("16");
    ui->LE_ikmin->setText("0,125");



    // QStringList to fill combo boxes
    material << "Vælg" << "Kobber" << "Aluminium";
    number << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10";
    conductors << "3" << "4"  << "5" << "3X1 række" << "3x1 trekant";
    crosssectionsCU << "1,5" << "2,5" << "4" << "6" << "10" << "16" << "25" << "35" << "50" << "70" << "95" << "120" << "150" << "185" << "240";
    crosssectionsAL <<  "16" << "25" << "35" << "50" << "70" << "95" << "120" << "150" << "185" << "240" << "300";
    crosssectionCon << "2,5" << "6" << "10" << "16" << "25" << "35" << "50" << "70" << "95" << "120";
    crosssectionPE << "2,5" << "6" << "10" << "16" << "25" << "35" << "50" << "70" << "95" << "120" << "150" << "240";
    PEplacement << "I kabel" << "Separat" << "Koncentrisk";

    // Reset labels so they dont show wierd stuff at startup
    ui->LdigramKabelET->setText("");
    ui->LdigramKabelETpe->setText("");


    // ----------- CABEL 1 ----------------------
    // ---   prepare cable 1 settings         ---
    // ------------------------------------------


    ui->CBkabelETmateriale->addItems(material);
    ui->CBkabelETantal->addItems(number);
    ui->CBkabelETconductors->addItems(conductors);
    ui->CBkabelETpenMateriale->addItems(material);
    ui->CBkabelETpenOplagt->addItems(PEplacement);
    ui->CBkabelETpenKvadrat->addItems(crosssectionsAL);
    ui->CBkabelETpenAntal->addItems(number);

    ui->CBkabelETconductors->setCurrentText("");
    ui->CBkabelETpenOplagt->setCurrentText("I kabel");
    ui->CBkabelETpenAntal->setCurrentText("1");
    ui->CBkabelETantal->setCurrentText("1");
    ui->LEkabelETlangde->setText("10");


    ui->CBkabelETkvadrat->setEnabled(false);
    ui->CBkabelETconductors->setEnabled(false);
    ui->CBkabelETantal->setEnabled(false);
    ui->LEkabelETlangde->setEnabled(false);
    ui->CBkabelETpenKvadrat->setEnabled(false);
    ui->CBkabelETpenMateriale->setEnabled(false);
    ui->CBkabelETpenAntal->setEnabled(false);
    ui->CBkabelETpenOplagt->setEnabled(false);

    ui->LkabelETingenX->setText("");
    ui->LkabelETingenX->setAutoFillBackground(false);



    // ----------- CABEL 2 ----------------------
    // ---   prepare cable 2 settings         ---
    // ------------------------------------------


    ui->CBkabelTOmateriale->addItems(material);
    ui->CBkabelTOantal->addItems(number);
    ui->CBkabelTOconductors->addItems(conductors);
    ui->CBkabelTOpenMateriale->addItems(material);
    ui->CBkabelTOpenOplagt->addItems(PEplacement);
    ui->CBkabelTOpenKvadrat->addItems(crosssectionsAL);
     ui->CBkabelTOpenAntal->addItems(number);

    ui->CBkabelTOconductors->setCurrentText("");
    ui->CBkabelTOpenOplagt->setCurrentText("I kabel");
    ui->CBkabelTOpenAntal->setCurrentText("1");
    ui->CBkabelTOantal->setCurrentText("1");
    ui->LEkabelTOlangde->setText("10");


    ui->CBkabelTOkvadrat->setEnabled(false);
    ui->CBkabelTOconductors->setEnabled(false);
    ui->CBkabelTOantal->setEnabled(false);
    ui->LEkabelTOlangde->setEnabled(false);
    ui->CBkabelTOpenKvadrat->setEnabled(false);
    ui->CBkabelTOpenMateriale->setEnabled(false);
    ui->CBkabelTOpenAntal->setEnabled(false);
    ui->CBkabelTOpenOplagt->setEnabled(false);

    ui->LkabelTOingenX->setText("");
    ui->LkabelTOingenX->setAutoFillBackground(false);


    // ----------- CABEL 3 ----------------------
    // ---   prepare cable 3 settings         ---
    // ------------------------------------------


    ui->CBkabelTREmateriale->addItems(material);
    ui->CBkabelTREantal->addItems(number);
    ui->CBkabelTREconductors->addItems(conductors);
    ui->CBkabelTREpenMateriale->addItems(material);
    ui->CBkabelTREpenOplagt->addItems(PEplacement);
    ui->CBkabelTREpenKvadrat->addItems(crosssectionsAL);
    ui->CBkabelTREpenAntal->addItems(number);

    ui->CBkabelTREconductors->setCurrentText("");
    ui->CBkabelTREpenOplagt->setCurrentText("I kabel");
    ui->CBkabelTREpenAntal->setCurrentText("1");
    ui->CBkabelTREantal->setCurrentText("1");
    ui->LEkabelTRElangde->setText("10");


    ui->CBkabelTREkvadrat->setEnabled(false);
    ui->CBkabelTREconductors->setEnabled(false);
    ui->CBkabelTREantal->setEnabled(false);
    ui->LEkabelTRElangde->setEnabled(false);
    ui->CBkabelTREpenKvadrat->setEnabled(false);
    ui->CBkabelTREpenMateriale->setEnabled(false);
    ui->CBkabelTREpenAntal->setEnabled(false);
    ui->CBkabelTREpenOplagt->setEnabled(false);

    ui->LkabelTREingenX->setText("");
    ui->LkabelTREingenX->setAutoFillBackground(false);

    //
    // Start maintain timer
    //

    QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(timertick()));
        timer->start(500);

}

MainWindow::~MainWindow()
{
    delete ui;
}



//
//  Cable materiel changed
//

void MainWindow::on_CBkabelETmateriale_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Kobber")
    {
        kabelET.setMaterial("cu");

         ui->CBkabelETkvadrat->clear();
         ui->CBkabelETkvadrat->addItems(crosssectionsCU);
         ui->CBkabelETkvadrat->setEnabled(true);
         ui->CBkabelETantal->setEnabled(true);
         ui->LEkabelETlangde->setEnabled(true);
         ui->CBkabelETpenOplagt->setEnabled(true);


    }
    else if (arg1 == "Aluminium")
    {
        kabelET.setMaterial("al");

        ui->CBkabelETkvadrat->clear();
        ui->CBkabelETkvadrat->addItems(crosssectionsAL);
        ui->CBkabelETkvadrat->setEnabled(true);
        ui->CBkabelETantal->setEnabled(true);
        ui->LEkabelETlangde->setEnabled(true);
         ui->CBkabelETpenOplagt->setEnabled(true);


    }
    else
    {
        ui->CBkabelETkvadrat->setEnabled(false);
        ui->CBkabelETconductors->setEnabled(false);
        ui->CBkabelETantal->setEnabled(false);
        ui->LEkabelETlangde->setEnabled(false);
        ui->CBkabelETpenOplagt->setEnabled(false);

    }

    setLabelCableOne();
    beregn();

}

void MainWindow::on_CBkabelTOmateriale_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Kobber")
    {
        kabelTO.setMaterial("cu");

         ui->CBkabelTOkvadrat->clear();
         ui->CBkabelTOkvadrat->addItems(crosssectionsCU);
         ui->CBkabelTOkvadrat->setEnabled(true);
         ui->CBkabelTOantal->setEnabled(true);
         ui->LEkabelTOlangde->setEnabled(true);
         ui->CBkabelTOpenOplagt->setEnabled(true);


    }
    else if (arg1 == "Aluminium")
    {
        kabelTO.setMaterial("al");

        ui->CBkabelTOkvadrat->clear();
        ui->CBkabelTOkvadrat->addItems(crosssectionsAL);
        ui->CBkabelTOkvadrat->setEnabled(true);
        ui->CBkabelTOantal->setEnabled(true);
        ui->LEkabelTOlangde->setEnabled(true);
         ui->CBkabelTOpenOplagt->setEnabled(true);


    }
    else
    {
        ui->CBkabelTOkvadrat->setEnabled(false);
        ui->CBkabelTOconductors->setEnabled(false);
        ui->CBkabelTOantal->setEnabled(false);
        ui->LEkabelTOlangde->setEnabled(false);
        ui->CBkabelTOpenOplagt->setEnabled(false);

    }

    setLabelCableTwo();
    beregn();
}

void MainWindow::on_CBkabelTREmateriale_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Kobber")
    {
        kabelTRE.setMaterial("cu");

         ui->CBkabelTREkvadrat->clear();
         ui->CBkabelTREkvadrat->addItems(crosssectionsCU);
         ui->CBkabelTREkvadrat->setEnabled(true);
         ui->CBkabelTREantal->setEnabled(true);
         ui->LEkabelTRElangde->setEnabled(true);
         ui->CBkabelTREpenOplagt->setEnabled(true);


    }
    else if (arg1 == "Aluminium")
    {
        kabelTRE.setMaterial("al");

        ui->CBkabelTREkvadrat->clear();
        ui->CBkabelTREkvadrat->addItems(crosssectionsAL);
        ui->CBkabelTREkvadrat->setEnabled(true);
        ui->CBkabelTREantal->setEnabled(true);
        ui->LEkabelTRElangde->setEnabled(true);
         ui->CBkabelTREpenOplagt->setEnabled(true);


    }
    else
    {
        ui->CBkabelTREkvadrat->setEnabled(false);
        ui->CBkabelTREconductors->setEnabled(false);
        ui->CBkabelTREantal->setEnabled(false);
        ui->LEkabelTRElangde->setEnabled(false);
        ui->CBkabelTREpenOplagt->setEnabled(false);

    }

    setLabelCableThree();
    beregn();
}

//
//  Cable crosssection changed
//


void MainWindow::on_CBkabelETkvadrat_currentTextChanged(const QString &arg1) //
{

    if (arg1 != "")
        {
            ui->CBkabelETconductors->setEnabled(true);
            kabelET.setCrosssection(arg1.toStdString());

        }
            else
            {
            ui->CBkabelETconductors->setEnabled(false);
            }
/*
    cout << kabelET.getR() << endl;

    if (ui->CBkabelETpenOplagt->currentText() == "I kabel")
    {
        kabelET.setCrosssectionPE(arg1.toStdString());
    }
*/

    setLabelCableOne();
    beregn();

}

void MainWindow::on_CBkabelTOkvadrat_currentTextChanged(const QString &arg1)
{
    if (arg1 != "")
        {
            ui->CBkabelTOconductors->setEnabled(true);
            kabelTO.setCrosssection(arg1.toStdString());

        }
            else
            {
            ui->CBkabelTOconductors->setEnabled(false);
            }


     setLabelCableTwo();
    beregn();
}

void MainWindow::on_CBkabelTREkvadrat_currentTextChanged(const QString &arg1)
{
    if (arg1 != "")
        {
            ui->CBkabelTREconductors->setEnabled(true);
            kabelTRE.setCrosssection(arg1.toStdString());

        }
            else
            {
            ui->CBkabelTREconductors->setEnabled(false);
            }


     setLabelCableThree();
    beregn();
}

//
//  Cable conducters changed
//

void MainWindow::on_CBkabelETconductors_currentTextChanged() // const QString &arg1
{

    /*
    QString crosssection;
    crosssection.fromStdString(kabelET.getCrosssection());



    kabelET.setConducters(arg1.toStdString());
    ui->LdigramKabelET->setText(arg1 + "G" + crosssection);
    */

    setLabelCableOne();
    beregn();
}



void MainWindow::on_CBkabelTOconductors_currentTextChanged() // const QString &arg1
{
    setLabelCableTwo();
    beregn();
}



void MainWindow::on_CBkabelTREconductors_currentTextChanged() // const QString &arg1
{
    setLabelCableThree();
    beregn();
}


///
//  Cable PEN placement changed
///

void MainWindow::on_CBkabelETpenOplagt_currentTextChanged(const QString &arg1)
{


    if (arg1 == "I kabel")
    {
        ui->CBkabelETpenKvadrat->setEnabled(false);
        ui->CBkabelETpenMateriale->setEnabled(false);
        ui->CBkabelETpenAntal->setCurrentText("1");
        ui->CBkabelETpenAntal->setEnabled(false);
    }

    else if (arg1 == "Separat")
    {
        ui->CBkabelETpenKvadrat->setEnabled(false);
        ui->CBkabelETpenMateriale->setEnabled(true);
            if (ui->CBkabelETpenMateriale->currentText() != "Vælg")
            {
                ui->CBkabelETpenKvadrat->setEnabled(true);
            }
        ui->CBkabelETpenAntal->setCurrentText("1");
        ui->CBkabelETpenKvadrat->clear();
        ui->CBkabelETpenKvadrat->addItems(crosssectionPE);
    }
    else if (arg1 == "Koncentrisk")
    {
        ui->CBkabelETpenKvadrat->clear();
        ui->CBkabelETpenKvadrat->addItems(crosssectionCon);
        ui->CBkabelETpenKvadrat->setEnabled(true);
        ui->CBkabelETpenMateriale->setEnabled(false);
        ui->CBkabelETpenMateriale->setCurrentText("Kobber");
        ui->CBkabelETpenAntal->setEnabled(false);
    }

    setLabelCableOne();
    beregn();

}






void MainWindow::on_CBkabelTOpenOplagt_currentTextChanged(const QString &arg1)
{
    if (arg1 == "I kabel")
    {
        ui->CBkabelTOpenKvadrat->setEnabled(false);
        ui->CBkabelTOpenMateriale->setEnabled(false);
        ui->CBkabelTOpenAntal->setCurrentText("1");
        ui->CBkabelTOpenAntal->setEnabled(false);
    }

    else if (arg1 == "Separat")
    {
        ui->CBkabelTOpenKvadrat->setEnabled(false);
        ui->CBkabelTOpenMateriale->setEnabled(true);
            if (ui->CBkabelTOpenMateriale->currentText() != "Vælg")
            {
                ui->CBkabelTOpenKvadrat->setEnabled(true);
            }
        ui->CBkabelTOpenAntal->setCurrentText("1");
        ui->CBkabelTOpenKvadrat->clear();
        ui->CBkabelTOpenKvadrat->addItems(crosssectionPE);
    }
    else if (arg1 == "Koncentrisk")
    {
        ui->CBkabelTOpenKvadrat->clear();
        ui->CBkabelTOpenKvadrat->addItems(crosssectionCon);
        ui->CBkabelTOpenKvadrat->setEnabled(true);
        ui->CBkabelTOpenMateriale->setEnabled(false);
        ui->CBkabelTOpenMateriale->setCurrentText("Kobber");
        ui->CBkabelTOpenAntal->setEnabled(false);
    }

    setLabelCableTwo();
    beregn();
}

void MainWindow::on_CBkabelTREpenOplagt_currentTextChanged(const QString &arg1)
{
    if (arg1 == "I kabel")
    {
        ui->CBkabelTREpenKvadrat->setEnabled(false);
        ui->CBkabelTREpenMateriale->setEnabled(false);
        ui->CBkabelTREpenAntal->setCurrentText("1");
        ui->CBkabelTREpenAntal->setEnabled(false);
    }

    else if (arg1 == "Separat")
    {
        ui->CBkabelTREpenKvadrat->setEnabled(false);
        ui->CBkabelTREpenMateriale->setEnabled(true);
            if (ui->CBkabelTREpenMateriale->currentText() != "Vælg")
            {
                ui->CBkabelTREpenKvadrat->setEnabled(true);
            }
        ui->CBkabelTREpenAntal->setCurrentText("1");
        ui->CBkabelTREpenKvadrat->clear();
        ui->CBkabelTREpenKvadrat->addItems(crosssectionPE);
    }
    else if (arg1 == "Koncentrisk")
    {
        ui->CBkabelTREpenKvadrat->clear();
        ui->CBkabelTREpenKvadrat->addItems(crosssectionCon);
        ui->CBkabelTREpenKvadrat->setEnabled(true);
        ui->CBkabelTREpenMateriale->setEnabled(false);
        ui->CBkabelTREpenMateriale->setCurrentText("Kobber");
        ui->CBkabelTREpenAntal->setEnabled(false);
    }

    setLabelCableThree();
    beregn();
}

///
//  Cable PEN material changed
///

void MainWindow::on_CBkabelETpenMateriale_currentTextChanged(const QString &arg1)
{
    if (arg1 != "Vælg")
    {
        ui->CBkabelETpenKvadrat->setEnabled(true);
        ui->CBkabelETpenAntal->setEnabled(true);
    }
    else
    {
        ui->CBkabelETpenKvadrat->setEnabled(false);
        ui->CBkabelETpenAntal->setEnabled(false);
    }

    beregn();
}

void MainWindow::on_CBkabelTOpenMateriale_currentTextChanged(const QString &arg1)
{
    if (arg1 != "Vælg")
    {
        ui->CBkabelTOpenKvadrat->setEnabled(true);
        ui->CBkabelTOpenAntal->setEnabled(true);
    }
    else
    {
        ui->CBkabelTOpenKvadrat->setEnabled(false);
        ui->CBkabelTOpenAntal->setEnabled(false);
    }

    beregn();
}

void MainWindow::on_CBkabelTREpenMateriale_currentTextChanged(const QString &arg1)
{
    if (arg1 != "Vælg")
    {
        ui->CBkabelTREpenKvadrat->setEnabled(true);
        ui->CBkabelTREpenAntal->setEnabled(true);
    }
    else
    {
        ui->CBkabelTREpenKvadrat->setEnabled(false);
        ui->CBkabelTREpenAntal->setEnabled(false);
    }

    beregn();
}

//
//  PEN crosssection changed
//

void MainWindow::on_CBkabelETpenKvadrat_currentTextChanged() //const QString &arg1
{
    setLabelCableOne();
    beregn();
}

void MainWindow::on_CBkabelTOpenKvadrat_currentTextChanged() // const QString &arg1
{
    setLabelCableTwo();
    beregn();
}




void MainWindow::on_CBkabelTREpenKvadrat_currentTextChanged() //const QString &arg1
{
     setLabelCableThree();
    beregn();
}

//
// Other calculate calls
//

void MainWindow::on_LEkabelETlangde_textChanged() //const QString &arg1
{
    beregn();
}

void MainWindow::on_LEkabelTOlangde_textChanged() //const QString &arg1
{
    beregn();
}

void MainWindow::on_LEkabelTRElangde_textChanged() //(const QString &arg1
{
    beregn();
}

void MainWindow::on_LEkabelETantal_textChanged() // const QString &arg1
{
    beregn();
}

void MainWindow::on_CBkabelETantal_currentTextChanged() //const QString &arg1
{
    beregn();
}

void MainWindow::on_CBkabelTOantal_currentTextChanged() // const QString &arg1
{
    beregn();
}

void MainWindow::on_CBkabelTREantal_currentTextChanged()
{
   beregn();
}



void MainWindow::on_CBkabelETpenAntal_currentTextChanged() //const QString &arg1
{
    beregn();
}




///
//  Load cable values
///


void MainWindow::loadCableOne()
{

    kabelET.setMaterial(ui->CBkabelETmateriale->currentText().toStdString());
    kabelET.setConducters(ui->CBkabelETconductors->currentText().toStdString());
    kabelET.setCrosssection(ui->CBkabelETkvadrat->currentText().toStdString());
    kabelET.setConcentric("0");
    if (ui->CBkabelETpenOplagt->currentText() != "I kabel")
    {
        kabelET.setMaterialPE(ui->CBkabelETpenMateriale->currentText().toStdString());
        kabelET.setCrosssectionPE(ui->CBkabelETpenKvadrat->currentText().toStdString());

        if (ui->CBkabelETpenOplagt->currentText() == "Koncentrisk")
        {
            kabelET.setConcentric("1");
        }

    }
    else
    {
    kabelET.setMaterialPE(ui->CBkabelETmateriale->currentText().toStdString());
    kabelET.setCrosssectionPE(ui->CBkabelETkvadrat->currentText().toStdString());
    }

    if (kabelET.getX() == 0.0)
    {
        kabelETingenX(false);
    }
    else
    {
        kabelETingenX(true);
    }

}

void MainWindow::loadCableTwo()
{

    kabelTO.setMaterial(ui->CBkabelTOmateriale->currentText().toStdString());
    kabelTO.setConducters(ui->CBkabelTOconductors->currentText().toStdString());
    kabelTO.setCrosssection(ui->CBkabelTOkvadrat->currentText().toStdString());
    kabelTO.setConcentric("0");
    if (ui->CBkabelTOpenOplagt->currentText() != "I kabel")
    {
        kabelTO.setMaterialPE(ui->CBkabelTOpenMateriale->currentText().toStdString());
        kabelTO.setCrosssectionPE(ui->CBkabelTOpenKvadrat->currentText().toStdString());

        if (ui->CBkabelTOpenOplagt->currentText() == "Koncentrisk")
        {
            kabelTO.setConcentric("1");
        }

    }
    else
    {
    kabelTO.setMaterialPE(ui->CBkabelTOmateriale->currentText().toStdString());
    kabelTO.setCrosssectionPE(ui->CBkabelTOkvadrat->currentText().toStdString());
    }

    if (kabelTO.getX() == 0.0)
    {
        kabelTOingenX(false);
    }
    else
    {
        kabelTOingenX(true);
    }

}

//
// No X value
//


void MainWindow::kabelETingenX(bool arg1)
{
    QPalette sample_palette;


    if (arg1 == true)
    {
        ui->LkabelETingenX->setAutoFillBackground(false);
        ui->LkabelETingenX->setPalette(sample_palette);

        ui->LkabelETingenX->setText("");


    }
    else if (ui->CBkabelETmateriale->currentText() != "Vælg")
    {
        sample_palette.setColor(QPalette::Window, Qt::red);
        ui->LkabelETingenX->setAutoFillBackground(true);
        ui->LkabelETingenX->setPalette(sample_palette);

        ui->LkabelETingenX->setAlignment(Qt::AlignCenter);
        ui->LkabelETingenX->setText("Ingen NKT X værdi fundet, bruger 0,08");


    }
}

void MainWindow::kabelTOingenX(bool arg1)
{
    QPalette sample_palette;


    if (arg1 == true)
    {
        ui->LkabelTOingenX->setAutoFillBackground(false);
        ui->LkabelTOingenX->setPalette(sample_palette);

        ui->LkabelTOingenX->setText("");

    }
    else if (ui->CBkabelTOmateriale->currentText() != "Vælg")
    {
        sample_palette.setColor(QPalette::Window, Qt::red);
        ui->LkabelTOingenX->setAutoFillBackground(true);
        ui->LkabelTOingenX->setPalette(sample_palette);

        ui->LkabelTOingenX->setAlignment(Qt::AlignCenter);
        ui->LkabelTOingenX->setText("Ingen NKT X værdi fundet, bruger 0,08");

    }
}

void MainWindow::beregn()
{
     time_t now = time(0);
    cout << now << " - Der regnes .. " << endl;
     double Znet, Rnet, Xnet;
     //double Rnetmax;
     // double RkabelET, XkabelET;


     try
     {
        loadCableOne();
        loadCableTwo();


    // Ikmax Z

    Znet = uri.getUf()/uri.getIkmax();
    Rnet = Znet*uri.getikmaxPF();
    Xnet = sqrt(pow(Znet,2.0)-pow(Rnet,2.0));






    // Ikmax A
    uri.setRmin(Rnet);
    uri.setXmin(Xnet);
    IkmaxA=uri.calcIkmax();

    //Ikmax B
    QString kabelETlangde = ui->LEkabelETlangde->text();
    double Rmin = Rnet + (kabelET.getR()*kabelETlangde.toDouble()/1000);
    double Xmin = Xnet + (kabelET.getX()*kabelETlangde.toDouble()/1000);

    uri.setRmin(Rmin);
    uri.setXmin(Xmin);
    IkmaxB=uri.calcIkmax();

    // Ikmin B
     uri.setRmax((uri.getUf()/uri.getIkmin()) + ((kabelET.getR() + kabelET.getRpe()) * kabelETlangde.toDouble() * 1.5 / 1000));
     IkminB = uri.getUf() / uri.getRmax();
   // IkminB = (kabelET.getR() + kabelET.getRpe()) * kabelETlangde.toDouble() * 1,5;

     //cout << "IkminB: " << IkminB << endl;
    // cout << "X1: " << kabelET.getX() << endl;


     //Ikmax C
     //QString kabelETlangde = ui->LEkabelETlangde->text();
     QString kabelTOlangde = ui->LEkabelTOlangde->text();
     Rmin = Rnet + (kabelET.getR()*kabelETlangde.toDouble()/1000) + (kabelTO.getR()*kabelTOlangde.toDouble()/1000);
     Xmin = Xnet + (kabelET.getX()*kabelETlangde.toDouble()/1000) + (kabelTO.getX()*kabelTOlangde.toDouble()/1000);

     uri.setRmin(Rmin);
     uri.setXmin(Xmin);
     IkmaxC=uri.calcIkmax();

     // Ikmin C
      uri.setRmax((uri.getUf()/uri.getIkmin()) + (((kabelET.getR() + kabelET.getRpe()) * kabelETlangde.toDouble()) + ((kabelTO.getR() + kabelTO.getRpe()) * kabelTOlangde.toDouble())) * 1.5 / 1000);
      IkminC = uri.getUf() / uri.getRmax();
    cout << "IkminC: " << IkminC << endl;


     }
     catch (exception& e)
     {
       cout << "Calculation went wrong: " << e.what() << endl;
     }

setDiagramLabels();

}

void MainWindow::setDiagramLabels()
{
    // label Amin Ikmin B
    QString labelb = "";
    labelb.append(QString::number(IkminB,'f',0));
    labelb.append(" A");
    ui->LdiagramBmin->setText(labelb);

    // label B Ikmax B
    QString labelB = "";
    labelB.append(QString::number(IkmaxB/1000,'f',2));
    labelB.append(" kA");
    ui->LdiagramB->setText(labelB);

    // Ikmin C
    QString labelc = "";
    labelc.append(QString::number(IkminC,'f',0));
    labelc.append(" A");
    ui->LdiagramCmin->setText(labelc);

    // label C Ikmax C
    QString labelC = "";
    labelC.append(QString::number(IkmaxC/1000,'f',2));
    labelC.append(" kA");
    ui->LdiagramC->setText(labelC);

}

//
// Set cable labes
//


void MainWindow::setLabelCableOne()
{
    QString label,pow;


   //pow = QString::fromUtf8("\u00B2");
    pow = tr("<sup>2</sup>");

    if (ui->CBkabelETmateriale->currentText() != "Vælg")
    {

    if (ui->CBkabelETconductors->currentText() == "3" || ui->CBkabelETconductors->currentText() == "4" || ui->CBkabelETconductors->currentText() == "5")
    {
        label = ui->CBkabelETconductors->currentText();
    }

    if (ui->CBkabelETpenOplagt->currentText() == "I kabel" && ui->CBkabelETconductors->currentText() != "4")
    {
    label.append("G");
    label.append(ui->CBkabelETkvadrat->currentText());
    }
    else if  ((ui->CBkabelETpenOplagt->currentText() != "I kabel") || ((ui->CBkabelETconductors->currentText() == "4") && (ui->CBkabelETpenOplagt->currentText() != "Koncentrisk"))) //Is this right?

     {
      label.append("X");
      label.append(ui->CBkabelETkvadrat->currentText());

     }

   if (ui->CBkabelETpenOplagt->currentText() == "Koncentrisk")
    {
        label.append(" + ");
        label.append(ui->CBkabelETpenKvadrat->currentText());

    }


    label.append(" mm");
    label.append(pow);



    ui->LdigramKabelET->setText(label);
    }
    else
    {
        ui->LdigramKabelET->setText("");
    }

    setLabelCableOnePe();
}

void MainWindow::setLabelCableTwo()
{
    QString label,pow;


   //pow = QString::fromUtf8("\u00B2");
    pow = tr("<sup>2</sup>");

    if (ui->CBkabelTOmateriale->currentText() != "Vælg")
    {

    if (ui->CBkabelTOconductors->currentText() == "3" || ui->CBkabelTOconductors->currentText() == "4" || ui->CBkabelTOconductors->currentText() == "5")
    {
        label = ui->CBkabelTOconductors->currentText();
    }

    if (ui->CBkabelTOpenOplagt->currentText() == "I kabel" && ui->CBkabelTOconductors->currentText() != "4")
    {
    label.append("G");
    label.append(ui->CBkabelTOkvadrat->currentText());
    }
    else if  ((ui->CBkabelTOpenOplagt->currentText() != "I kabel") || ((ui->CBkabelTOconductors->currentText() == "4") && (ui->CBkabelTOpenOplagt->currentText() != "Koncentrisk"))) //Is this right?

     {
      label.append("X");
      label.append(ui->CBkabelTOkvadrat->currentText());

     }

   if (ui->CBkabelTOpenOplagt->currentText() == "Koncentrisk")
    {
        label.append(" + ");
        label.append(ui->CBkabelTOpenKvadrat->currentText());

    }


    label.append(" mm");
    label.append(pow);



    ui->LdigramKabelTO->setText(label);
    }
    else
    {
        ui->LdigramKabelTO->setText("");
    }

    setLabelCableTwoPe();
}

void MainWindow::setLabelCableThree()
{
    QString label,pow;


   //pow = QString::fromUtf8("\u00B2");
    pow = tr("<sup>2</sup>");

    if (ui->CBkabelTREmateriale->currentText() != "Vælg")
    {

    if (ui->CBkabelTREconductors->currentText() == "3" || ui->CBkabelTREconductors->currentText() == "4" || ui->CBkabelTREconductors->currentText() == "5")
    {
        label = ui->CBkabelTREconductors->currentText();
    }

    if (ui->CBkabelTREpenOplagt->currentText() == "I kabel" && ui->CBkabelTREconductors->currentText() != "4")
    {
    label.append("G");
    label.append(ui->CBkabelTREkvadrat->currentText());
    }
    else if  ((ui->CBkabelTREpenOplagt->currentText() != "I kabel") || ((ui->CBkabelTREconductors->currentText() == "4") && (ui->CBkabelTREpenOplagt->currentText() != "Koncentrisk"))) //Is this right?

     {
      label.append("X");
      label.append(ui->CBkabelTREkvadrat->currentText());

     }

   if (ui->CBkabelTREpenOplagt->currentText() == "Koncentrisk")
    {
        label.append(" + ");
        label.append(ui->CBkabelTREpenKvadrat->currentText());

    }


    label.append(" mm");
    label.append(pow);



    ui->LdiagramKabelTRE->setText(label);
    }
    else
    {
        ui->LdiagramKabelTRE->setText("");
    }

    setLabelCableThreePe();
}

void MainWindow::setLabelCableOnePe()
{

    QString label,pow;


    pow = tr("<sup>2</sup>");

    if (ui->CBkabelETpenOplagt->currentText() == "Separat")
    {
        label.append("1G");


    label.append(ui->CBkabelETpenKvadrat->currentText());

    label.append(" mm");
    label.append(pow);

    ui->LdigramKabelETpe->setText(label);


    }
    else
       ui->LdigramKabelETpe->setText("");


}

void MainWindow::setLabelCableTwoPe()
{

    QString label,pow;


    pow = tr("<sup>2</sup>");

    if (ui->CBkabelTOpenOplagt->currentText() == "Separat")
    {
        label.append("1G");


    label.append(ui->CBkabelTOpenKvadrat->currentText());

    label.append(" mm");
    label.append(pow);

    ui->LdigramKabelTOpe->setText(label);


    }
    else
       ui->LdigramKabelTOpe->setText("");


}

void MainWindow::setLabelCableThreePe()
{

    QString label,pow;


    pow = tr("<sup>2</sup>");

    if (ui->CBkabelTREpenOplagt->currentText() == "Separat")
    {
        label.append("1G");


    label.append(ui->CBkabelTREpenKvadrat->currentText());

    label.append(" mm");
    label.append(pow);

    ui->LdiagramKabelTREpe->setText(label);


    }
    else
       ui->LdiagramKabelTREpe->setText("");


}


void MainWindow::on_LE_ikmax_textChanged(const QString &arg1)
{
     // Ikmax changed

    QString ikmax;
    QString temp = arg1;

    ikmax = arg1 + " kA";

    ui->LdiagramA->setText(ikmax);
    // str.replace(QString("ou"), QString("o"));
    temp.replace(QString(","),QString("."));



    uri.setIkmax(temp.toDouble()*1000);

    beregn();
}

void MainWindow::on_LE_ikmin_textChanged(const QString &ikmin)
{


    QString temp = ikmin;
    double iktemp;


    temp.replace(QString(","),QString("."));

    iktemp = temp.toDouble()*1000;
    uri.setIkmin(iktemp);

    //cout << temp.toStdString() << endl;

    temp = QString::number(iktemp,'f', 0);
    temp.append(" A");

    ui->LdiagramAmin->setText(temp);

    beregn();

}



void MainWindow::on_actionOm_elektro3_triggered()
{
  about.show();

}

void MainWindow::test()
{
    cout << "test" << endl;
}

void MainWindow::on_actionIndstillinger_triggered()
{
    indstillinger.show();
}

void MainWindow::timertick()
{

    // check to reload config settings
    if (indstillinger.isVisible())
    {
        propDiaOpen = true;
    }
    if (!indstillinger.isVisible() && propDiaOpen == true)
    {
        // properties dialog was open
        loadConfig();
        propDiaOpen = false;
    }



}

void MainWindow::loadConfig()
{
    config conf;
    vector<string> confs;

    confs = conf.readConfig();

    ui->labelStatus->setText(QString::fromStdString(confs.at(1)));
}
