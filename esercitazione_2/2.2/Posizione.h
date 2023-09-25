#ifndef __Posizione_h__
#define __Posizione_h__
#include <iostream>
using namespace std;

class Posizione {

public:

Posizione();
Posizione(double x, double y,double z );
~Posizione();
double Getx() const ;
double Gety() const ;
double Getz() const ;
double GetR() const;
double Gettheta() const ;
double Getphi() const;
double Getrho() const; 
double Distanza(const Posizione &p) const ;
void Setx(double);
void Sety(double);
void Setz(double);
protected:
double m_x, m_y, m_z;    

};

#endif // __Posizione_h__
