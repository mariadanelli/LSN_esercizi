#include "Posizione.h"
#include <iostream>
#include <cmath>
using namespace std;

Posizione:: Posizione() {
m_x=0;
m_y=0;
}

Posizione:: Posizione(double x, double y) {
m_x=x;
m_y=y;

}

Posizione:: ~ Posizione() {}

double Posizione:: Getx () const {
return m_x;
}

double Posizione:: Gety () const {
return m_y;
}


double Posizione:: GetR () const {
return sqrt(pow(m_x,2)+ pow(m_y,2));
}

double Posizione:: Gettheta () const {
return atan2(m_y,m_x );
}

double Posizione:: Getrho () const {
return m_x*m_x+ m_y*m_y;
}

double Posizione:: Distanza (const Posizione &p) const {
return sqrt((p.Getx()- Getx())* (p.Getx()- Getx()) + (p.Gety()- Gety())*(p.Gety()- Gety()))  ;
}

void Posizione::Setx (double x) {
	m_x=x;
}

void Posizione::Sety (double x) {
	m_y=x;
}
