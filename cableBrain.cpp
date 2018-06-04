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
   

    cableX.clear();
    cableX.push_back("cu;1,5;3;0.103;0");
 



}
