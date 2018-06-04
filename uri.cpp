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
 * File:   uri.cpp
 * Author: krm
 * 
 * Created on 13. marts 2018, 19:27
 */

#include "uri.h"



uri::uri() {
}

uri::uri(const uri& orig) {
}

uri::~uri() {
}

void uri::setIkmax(double arg1)
{
   ikmax = arg1;
}

void uri::setIkmin(double arg1)
{
   ikmin = arg1;
}

void uri::setUn(double arg1)
{
    Un = arg1;
    Uf = Un/sqrt(3);
}

void uri::setPF(double arg1)
{
    ikmaxPF = arg1;
}

void uri::setRmax(double arg1)
{
    Rmax = arg1;
    cout << "Rmax: " << Rmax << endl;
}

void uri::setRmin(double arg1)
{
    Rmin = arg1;
    //cout << "Rmin: " << Rmin << endl;
}

void uri::setXmin(double arg1)
{
    Xmin = arg1;
    //cout << "Xmin: " << Xmin << endl;
}


/*
 *
 *    double getIkmax(double Rmin, double Xmin);
    double getImin(double Rmax);

private:

    double ikmax = 0.0;
    double ikmin = 0.0;
    double Unet = 400.0;
    double Uf = Unet/sqrt(3);
    double ikmaxPF = 0.3;
    double Rmax = 0.0;
    double Rmin = 0.0;
    double Xmin = 0.0;
*/

double uri::getRmax() {
    return Rmax;
}

double uri::getRmin() {
    return Rmin;
}

double uri::getXmin() {
    return Xmin;
}

double uri::getIkmax() {
    return ikmax;

}

double uri::getIkmin()
{
    return ikmin;
}

double uri::getikmaxPF() {
    return ikmaxPF;
}

double uri::calcIkmax() {
    cout << Uf/(sqrt(pow(Rmin,2.0)+pow(Xmin,2.0))) << endl;
    return Uf/(sqrt(pow(Rmin,2.0)+pow(Xmin,2.0)));
}

double uri::calcIkmin() {

    return 0.0;
}



double uri::getUf() {
    return Uf;
}

