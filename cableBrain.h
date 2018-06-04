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
 * File:   cableBrain.h
 * Author: km
 *
 * Created on 15. marts 2018, 08:44
 */

#ifndef CABLEBRAIN_H
#define CABLEBRAIN_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class cableBrain {
public:
    cableBrain();
    cableBrain(const cableBrain& orig);
    virtual ~cableBrain();
    void setCrosssection(string arg1);
    void setCrosssectionPE(string arg1);
    string getCrosssection();
    void setMaterial(string arg1);
    void setMaterialPE(string arg1);
    void setConducters(string arg1);
    void setConcentric(string arg1);
    string getConducters();
    string getMaterial();
    double getR(); //string kvadrat, string metal
    double getRpe();
    double getX(); // string kvadrat, string metal, int ledere, int concentrisk

    double calcR(double lenght, double denominator);
    bool noX;
    bool alternativeX;


private:
    void readCableDataR();
    void readCableDataX();
    const vector<string> explode(const string& s, const char& c);
    void loadCabledata();

    vector<string>cableR;
    vector<string>cableX;
    vector<string> cableDataR;
    vector<string> cableDataX;
    string crosssection;
    string crosssectionPE;
    string material, materialPE;
    string conducters;
    string concentric;
    double R,Rpe;
    double X;


};



#endif /* CABLEBRAIN_H */

