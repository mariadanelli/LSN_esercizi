#pragma once 

#include <iostream>
using namespace std;

class Posizione {

public:

Posizione();
Posizione(double x, double y );
~Posizione();
double Getx() const ;
double Gety() const ;
double GetR() const;
double Gettheta() const ;
double Getphi() const;
double Getrho() const; 
double Distanza(const Posizione &p) const ;
void Setx(double);
void Sety(double);

protected:
double m_x, m_y;    

};
