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

/* 
 * File:   cableBrain.cpp
 * Author: krm
 * 
 * Created on 15. marts 2018, 08:44
 */



#include "cableBrain.h"


cableBrain::cableBrain() {
    cableBrain::loadCabledata();

}

//cableBrain::cableBrain(const cableBrain& orig) {
//
//}

cableBrain::~cableBrain() {
}



////
// Public Parts
////

void cableBrain::setCrosssection(string arg1)
{
    crosssection = arg1;
    cout << "mm2 :" << arg1;
}

string cableBrain::getCrosssection()
{
    return crosssection;
}

void cableBrain::setCrosssectionPE(string arg1)
{
    crosssectionPE = arg1;
}

void cableBrain::setMaterial(string arg1)
{
    if (arg1 == "Kobber")
    {
        material = "cu";
    }

    else if (arg1 == "Aluminium")
    {
        material = "al";
    }
}

void cableBrain::setMaterialPE(string arg1)
{
    if (arg1 == "Kobber")
    {
        materialPE = "cu";
    }

    else if (arg1 == "Aluminium")
    {
        materialPE = "al";
    }


}

void cableBrain::setConducters(string arg1)
{
    conducters = arg1;
}

void cableBrain::setConcentric(string arg1)
{
    concentric = arg1;
}

string cableBrain::getConducters()
{
    return conducters;
}

string cableBrain::getMaterial()
{
    return material;
}

double cableBrain::getR()
{
    double returnValue = 0.0;
     
    if (cableR.size() < 1)
    {
        cableBrain::loadCabledata();
    }
    
    for (string line : cableR)
    {
        vector<string> pieces = explode(line, ';');
       // cout << "Leder efter R" << endl;

        if (pieces.size() > 0 && pieces.at(0) == material && pieces.at(1) == crosssection)
        {
            returnValue = stod(pieces.at(2));
        }
        
    }
    R = returnValue;
    cout << R << endl;
    return returnValue;
    
}

double cableBrain::getRpe()
{
    double returnValue = 0.0;

    if (cableR.size() < 1)
    {
        cableBrain::loadCabledata();
    }

    for (string line : cableR)
    {
        vector<string> pieces = explode(line, ';');
       // cout << "Leder efter R" << endl;

        if (pieces.size() > 0 && pieces.at(0) == materialPE && pieces.at(1) == crosssectionPE)
        {
            returnValue = stod(pieces.at(2));
        }

    }
    R = returnValue;
    cout << "Rpe: " << R << endl;
    return returnValue;
}

double cableBrain::calcR(double lenght, double denominator) // return the total R for a cable incl lenght - if ohm is given in km and lenght in meters - use 1000 as denominator
{
    if (denominator == 0.0) {denominator = 1;}
    return (R*lenght)/denominator;
}

  double cableBrain::getX()
  {
      double returnValue = 0.0;

      if (alternativeX = true)
      {
          returnValue = 0.08;
      }

      if (cableX.size() < 1)
      {
          cableBrain::loadCabledata();
      }

      for (string line : cableX)
      {
          vector<string> pieces = explode(line, ';');
          //cout << "Leder efter X " << pieces.at(0) << " " << material << " - " << pieces.at(1) << " " << crosssection << " - " << pieces.at(2) << " " << conducters << " - " << pieces.at(4) << " " << concentric << endl;

          if (pieces.size() > 0 && pieces.at(0) == material && pieces.at(1) == crosssection && pieces.at(2) == conducters && pieces.at(4) == concentric)
          {
              returnValue = stod(pieces.at(3));
          }

      }
      X = returnValue;
      cout << X << endl;



      return returnValue;
  }

////
// Private Parts
////

void cableBrain::readCableDataR()
{
    
    ifstream Rdatafile;
    string line = "";
    
    try {
        Rdatafile.open("kabeldata_r.les");
    } catch (ifstream::failure e) {
        cout << "Der er sket en fejl" << endl;
    }
    
    if (Rdatafile.fail())
    {
        cout << "Fejl ved åbning af R datafil";
    }
    
     while (Rdatafile)
        {
            // Switch LightRapos "Trappe" <light> ["Lighting"] {ihc="0x89a5b"}
            getline(Rdatafile, line);
            cableDataR.push_back(line);
     }
}


void cableBrain::readCableDataX()
{
        ifstream Xdatafile;
        string line = "";
    
    try {
        Xdatafile.open("kabeldata_x.les");
    } catch (ifstream::failure e) {
        cout << "Der er sket en fejl" << endl;
    }
    
    if (Xdatafile.fail())
    {
        cout << "Fejl ved åbning af X datafil";
    }
    
     while (Xdatafile)
        {

            getline(Xdatafile, line);
            cableDataX.push_back(line);
     }
}

const vector<string> cableBrain::explode(const string& s, const char& c)
{
    string buff;
    buff = "";
    vector<string> v;
    int counter = 0; // Der skal tælles "
    
    for(auto n:s)
    {
        
        
        if(n == '\"') {
            counter ++;
        }
        
        if (counter == 1 && n == c)
        {
            //buff = buff + "-";
            buff+=n;
        }
        else
            
            if(n != c)
            {
                buff+=n;
            }
        
            else
                if(n == c && buff != "" && (counter == 2 || counter == 0))
                {
                    v.push_back(buff);
                    buff = "";
                    counter = 0;
                    
                }
    }
    if(buff != "") v.push_back(buff);
    
    return v;
}

void cableBrain::loadCabledata()
{
    cableR.clear();
    cableR.push_back("cu;1,5;12.1"); // materiel;crosssection;ohm/km
    cableR.push_back("cu;2,5;7.41");
    cableR.push_back("cu;4;4.61");
    cableR.push_back("cu;6;3.08");
    cableR.push_back("cu;10;1.83");
    cableR.push_back("cu;16;1.15");
    cableR.push_back("cu;25;0.727");
    cableR.push_back("cu;35;0.525");
    cableR.push_back("cu;50;0.388");
    cableR.push_back("cu;70;0.269");
    cableR.push_back("cu;95;0.194");
    cableR.push_back("cu;120;0.155");
    cableR.push_back("cu;185;0.1017");
    cableR.push_back("cu;240;0.0787");
    cableR.push_back("al;16;1.91");
    cableR.push_back("al;25;1.2");
    cableR.push_back("al;35;0.868");
    cableR.push_back("al;50;0.641");
    cableR.push_back("al;70;0.444");
    cableR.push_back("al;95;0.321");
    cableR.push_back("al;120;0.254");
    cableR.push_back("al;150;0.207");
    cableR.push_back("al;185;0.166");
    cableR.push_back("al;240;0.127");
    cableR.push_back("al;300;0.103");

    cableX.clear();
    cableX.push_back("cu;1,5;3;0.103;0");
    cableX.push_back("cu;1,5;4;0.110;0");
    cableX.push_back("cu;1,5;5;0.113;0");
    cableX.push_back("cu;2,5;3;0.095;0");
    cableX.push_back("cu;2,5;4;0.102;0");
    cableX.push_back("cu;2,5;5;0.105;0");
    cableX.push_back("cu;2,5;3;0.095;1");
    cableX.push_back("cu;4;3;0.089;0");
    cableX.push_back("cu;4;4;0.096;0");
    cableX.push_back("cu;4;5;0.099;0");
    cableX.push_back("cu;4;3;0.089;1");
    cableX.push_back("cu;6;3;0.087;0");
    cableX.push_back("cu;6;4;0.094;0");
    cableX.push_back("cu;6;5;0.097;0");
    cableX.push_back("cu;6;3;0.087;1");
    cableX.push_back("cu;10;3;0.082;0");
    cableX.push_back("cu;10;4;0.089;0");
    cableX.push_back("cu;10;5;0.092;0");
    cableX.push_back("cu;10;3;0.082;1");
    cableX.push_back("al;10;5;0.097;0");
    cableX.push_back("cu;16;3;0.078;0");
    cableX.push_back("cu;16;4;0.085;0");
    cableX.push_back("cu;16;5;0.088;0");
    cableX.push_back("cu;16;3;0,078;1");
    cableX.push_back("al;16;4;0.089;0");
    cableX.push_back("al;16;5;0.092;0");

    cableX.push_back("cu;25;3;0.079;0");
    cableX.push_back("cu;25;4;0.086;0");
    cableX.push_back("cu;25;5;0.089;0");
    cableX.push_back("cu;25;3;0.077;1");

    cableX.push_back("cu;25;3;0.077;1"); // materiel;crosssection;number of conducters;ohm/km;concentrical(bool)
    cableX.push_back("al;25;4;0.084;0");
    cableX.push_back("al;25;5;0.087;0");
    cableX.push_back("cu;35;3;0.074;0");
    cableX.push_back("cu;35;4;0.082;0");
    cableX.push_back("cu;35;5;0.085;0");
    cableX.push_back("cu;35;3;0.070;0");
    cableX.push_back("cu;50;4;0.084;0");
    cableX.push_back("cu;50;3;0.074;1");
    cableX.push_back("cu;50;4;0.080;1");
    cableX.push_back("al;50;3;0.074;1");
    cableX.push_back("al;50;4;0.080;1");
    cableX.push_back("al;50;4;0.081;0");
    cableX.push_back("cu;70;4;0.081;0");
    cableX.push_back("cu;70;3;0.073;1");
    cableX.push_back("cu;70;4;0.079;1");
    cableX.push_back("al;70;3;0.073;1");
    cableX.push_back("al;70;4;0.079;1");
    cableX.push_back("al;70;4;0.080;0");
    cableX.push_back("cu;95;4;0.082;0");
    cableX.push_back("cu;95;3;0.071;1");
    cableX.push_back("cu;95;4;0.077;1");
    cableX.push_back("al;95;3;0.071;1");
    cableX.push_back("al;95;4;0.077;1");
    cableX.push_back("al;95;4;0.078;0");
    cableX.push_back("cu;120;4;0.082;0");
    cableX.push_back("cu;120;3;0.070;1");
    cableX.push_back("cu;120;4;0.077;1");
    cableX.push_back("al;120;3;0.070;1");
    cableX.push_back("al;120;4;0.077;1");
    cableX.push_back("al;120;4;0.077;0");
    cableX.push_back("cu;150;4;0.084;0");
    cableX.push_back("cu;150;3;0.071;1");
    cableX.push_back("cu;150;4;0.077;1");
    cableX.push_back("al;150;3;0.071;1");
    cableX.push_back("al;150;4;0.077;1");
    cableX.push_back("al;150;4;0.078;0");
    cableX.push_back("cu;185;4;0.082;0");
    cableX.push_back("cu;185;3;0.071;1");
    cableX.push_back("cu;185;4;0.077;1");
    cableX.push_back("al;185;3;0.071;1");
    cableX.push_back("al;185;4;0.077;1");
    cableX.push_back("al;185;4;0.078;0");
    cableX.push_back("cu;240;4;0.083;0");
    cableX.push_back("cu;240;3;0.070;1");
    cableX.push_back("cu;240;4;0.077;1");
    cableX.push_back("al;240;3;0.070;1");
    cableX.push_back("al;240;4;0.077;1");
    cableX.push_back("al;240;4;0.077;0");
    cableX.push_back("al;300;4;0.077;0");



}
