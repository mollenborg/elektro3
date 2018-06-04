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
 * File:   uri.h
 * Author: krm
 *
 * Created on 13. marts 2018, 19:27
 */

#ifndef URI_H
#define URI_H

#include <math.h>
#include <iostream>

using namespace std;

class uri {
public:
    uri();
    uri(const uri& orig);
    virtual ~uri();
    void setIkmax(double arg1);
    void setIkmin(double arg1);
    void setUn(double arg1);
    void setPF(double arg1);
    void setRmax(double arg1);
    void setRmin(double arg1);
    void setXmin(double arg1);
    double getRmax();
    double getRmin();
    double getXmin();
    double getIkmax();
    double getIkmin();
    double getikmaxPF();
    double calcIkmax();
    double calcIkmin();
    double getImin(double Rmax);
    double getUf();
    double getUn();

private:

    double ikmax = 0.0;
    double ikmin = 0.0;
    double Un = 400.0;
    double Uf = Un/sqrt(3);
    double ikmaxPF = 0.3;
    double Rmax = 0.0;
    double Rmin = 0.0;
    double Xmin = 0.0;

};

#endif /* URI_H */

