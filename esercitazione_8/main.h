/****************************************************************
*****************************************************************
    _/    _/  _/_/_/  _/       Numerical Simulation Laboratory
   _/_/  _/ _/       _/       Physics Department
  _/  _/_/    _/    _/       Universita' degli Studi di Milano
 _/    _/       _/ _/       Prof. D.E. Galli
_/    _/  _/_/_/  _/_/_/_/ email: Davide.Galli@unimi.it
*****************************************************************
*****************************************************************/

#ifndef __fluid__
#define __fluid__

//Random numbers
#include "../random.h"
int seed[4];
Random rnd;

//parameters, observables
const int m_props=2000;
int n_props, iu, nstep_ott, acceptedSA, attemptedSA;
double vtail, ptail, bin_size, nbins, sd;
double walker[m_props];

//g(r)

int const nbin=500;

// averages
double blk_av[m_props], blk_norm, accepted, attempted;
double glob_av[m_props], glob_av2[m_props];
double stima_u;
double err_u;

//configuration


// thermodynamical state
int npart;
double beta,temp,energy,vol,rho,box,rcut;

// simulation
int iNVET, nstep, nblk, restart;
double delta, xold, mu, sigma, deltat, deltaott;

//pigreco
const double pi=3.1415927;

//functions
void Input(void);
void Reset(int);
void Accumulate(void);
vector <double> Averages(int);
void Move(double, double);
void Measure(double, double, double);
double Pbc(double);
double Error(double,double,int);
double Gaussiana (double x, double sigma, double mu);
double Psi(double x, double sigma, double mu);
double Psi2(double x, double sigma, double mu);
double Potential(double x);
double Hamilton( double x, double sigma, double mu);
vector <double> valmedH(double, double, bool, ofstream&, ofstream&);
void Equilibrazione(void);


#endif

/****************************************************************
*****************************************************************
    _/    _/  _/_/_/  _/       Numerical Simulation Laboratory
   _/_/  _/ _/       _/       Physics Department
  _/  _/_/    _/    _/       Universita' degli Studi di Milano
 _/    _/       _/ _/       Prof. D.E. Galli
_/    _/  _/_/_/  _/_/_/_/ email: Davide.Galli@unimi.it
*****************************************************************
*****************************************************************/
