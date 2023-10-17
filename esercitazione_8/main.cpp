/****************************************************************
*****************************************************************
    _/    _/  _/_/_/  _/       Numerical Simulation Laboratory
   _/_/  _/ _/       _/       Physics Department
  _/  _/_/    _/    _/       Universita' degli Studi di Milano
 _/    _/       _/ _/       Prof. D.E. Galli
_/    _/  _/_/_/  _/_/_/_/ email: Davide.Galli@unimi.it
*****************************************************************
*****************************************************************/

#include <iostream>
#include <fstream>
#include <ostream>
#include <cmath>
#include <iomanip>
#include <algorithm> 
#include "main.h"



using namespace std;


int main()


{
ofstream eneout;
eneout.open("EnediT.dat");

ofstream out;
out.open("sample.dat");

ofstream out2;
out2.open("Hbest.dat");
Input();

double p, H, H_new;
int k=0;
do {	
	temp=temp*deltat;
	beta=1./temp;

  
           p;
           H= valmedH(sigma, mu, 0, out, out2) [0];
           double sigma_new = fabs( sigma+ deltaott*(0.5-rnd.Rannyu()));
           double mu_new =fabs( mu+ deltaott*(0.5-rnd.Rannyu())); 
           
           H_new= valmedH(sigma_new,mu_new, 0, out, out2) [0];

                    p=min (1., exp(-beta*(H_new-H)));
                  
                        if (rnd.Rannyu()<=p) {
                            sigma=sigma_new;
                            mu=mu_new;
                            H=H_new;
                            acceptedSA++;
                          
                        }
                        
                        
                        
                        attemptedSA++;

      
        cout<<double(acceptedSA)/double(attemptedSA)<<endl;
             
                eneout<<temp<<"    "<<H<<"    "<< valmedH(sigma, mu, 0, out, out2) [1]<<"    "<<sigma<<"    "<<mu<< "   "<<endl; 
                k++;
  } while (temp>= 0.000001); 

ifstream in;
in.open("EnediT");
double hmin, sigmamin, mumin, err;
in>>temp>>hmin>>err>>sigmamin>>mumin;

for (int i=0; i<k; i++) {
    in>>temp>>H>>err>> sigma>> mu;
    if(H<hmin) {
      sigmamin= sigma;
      mumin= mu;
    } 
  }
  in.close();
  
vector <double> Hott= valmedH(sigmamin ,mumin, 1, out, out2);
cout<<sigmamin<<mumin;
 out.close();
  return 0;
}



/*
		 for(int iblk=1; iblk <= nblk; ++iblk) //Simulation
  {
    Reset(iblk);   //Reset block averages
    for(int istep=1; istep <= nstep; ++istep)
    {
      Move();
			//if (j==nstep_ott-1) {}
      // out<<x_old<<endl;
      Measure(x_old, sigma, mu);
      Accumulate(); //Update block averages
    }
    Averages(iblk);   //Print results for current block

  }
 //Write final configuration		
  enein.open("output.dat");
  out.close();
	 enein>> H_new;
	 getline(enein, ene);
	 H_old= H_new;
	 eneout<<ene<<endl;
	 enein.close();*/
    
   /* double p;
   H= valmedH(mu, sigma, 0, out) [0];
   double sigma_new = sigma+ deltaott*(0.5-rnd.Rannyu());
   double mu_new = mu+ deltaott*(0.5-rnd.Rannyu()); 
   H_new= valmedH(mu_new, sigma_new, 0, out) [0];

   		p= exp(-beta*(H_new-H));

			 if (rnd.Rannyu()<p) {
			    sigma=sigma_new;
                mu=mu_new;
                H=H_new;
				 acceptedSA++;
			 }
             
             
              
			attemptedSA++;

	}
    
    eneout<<temp<<"    "<<H<<"    "<< valmedH(mu, sigma, 0, out) [1]<<"    "<<mu<<"    "<<sigma<< "   "<<endl;
	} while (temp>0.00000000001); */

// sampliamo con mu e sigma ottimali




vector <double> valmedH(double sigma, double mu, bool s, ofstream& out, ofstream& out2) {

vector <double>  final;


 for(int iblk=1; iblk <= nblk; ++iblk) //Simulation
  {
    Reset(iblk);   //Reset block averages
    for(int istep=1; istep <= nstep; ++istep)
    {
      Move(sigma, mu); 
      
      	if (s == 1) {
       out<<xold<<endl;
       //normalizzazione
      /* norm ++  Psi2(x_old, sigma, mu)*deltabins; */ ; 
        }
      Measure(xold, sigma, mu);
      Accumulate(); //Update block averages
    }
 final = Averages(iblk); 
  if (s==1) {
  out2<<final[0]<<"    "<<final[1]<< endl;}
   //Print results for current block
  }

 

 return final;
}


    

  



void Input(void)
{
  ifstream ReadInput, ReadConf, ReadVelocity, Primes, Seed;


//Read seed for random numbers
  int p1, p2, p3, p4;
  Primes.open("../Primes");
  Primes >> p1 >> p2 ;
  Primes.close();

//Read input informations
  ReadInput.open("input.in");

  

  Seed.open("../seed.in");
  Seed >> seed[0] >> seed[1] >> seed[2] >> seed[3];
  rnd.SetRandom(seed,p1, p2);
  Seed.close();

  ReadInput >> temp;
  beta = 1.0/temp;
  cout << "Temperature = " << temp << endl;

    
  ReadInput >> delta;

  ReadInput >> nblk;

  ReadInput >> nstep;

  ReadInput >> xold;

  ReadInput>> mu;

  ReadInput>> sigma;
  
  ReadInput>> deltat;

  ReadInput >> nstep_ott;

  ReadInput >> deltaott;

  cout << "Moves parameter = " << delta << endl;
  cout << "Number of blocks = " << nblk << endl;
  cout << "Number of steps in one block = " << nstep << endl << endl;
  ReadInput.close();

//Prepare arrays for measurements
   iu = 0; //Total energy

  n_props = 1; //Number of observables
  return;
}


void Move(double sigma, double mu)
{
  double p, p_old, p_new;

    //Old


       p_old = Psi2(xold, sigma, mu);
     

    //New
     double x = ( xold + delta*(rnd.Rannyu() - 0.5) );


    
       p_new = Psi2(x,sigma, mu);

    //Metropolis test
  
      p = min(1., p_new/p_old);
      
      if(p > rnd.Rannyu())  
      {
      //Update
        xold = x;
    
        accepted = accepted + 1.0;}
      
      attempted = attempted + 1.0;

    }






void Measure(double x, double sigma, double mu) //Properties measurement
{
  double E_loc= Hamilton (x, sigma, mu);
  walker[iu]= E_loc;
  return;
}


void Reset(int iblk) //Reset block averages
{
   
   if(iblk == 1)
   {
       for(int i=0; i<m_props; ++i)
       {
           glob_av[i] = 0;
           glob_av2[i] = 0;
       }
   }

   for(int i=0; i<m_props; ++i)
   {
     blk_av[i] = 0;
   }
   blk_norm = 0;
   attempted = 0;
   accepted = 0;
}


void Accumulate(void) //Update block averages
{

   for(int i=0; i<m_props; ++i)
   {
     blk_av[i] = blk_av[i] + walker[i];
		 walker[i]=0;
   }
   blk_norm = blk_norm + 1.0;
}


vector <double> Averages(int iblk) //Print results for current block
{
    vector <double> final;
   const int wd=18;
   //cout << "Block number " << iblk << endl;
   // cout << "Acceptance rate " << accepted/attempted << endl << endl;
    
    
    stima_u = blk_av[iu]/blk_norm; //Energy
    glob_av[iu]  += stima_u;
    glob_av2[iu] += stima_u*stima_u;
    final.push_back(glob_av[iu]/ double (iblk));
    err_u=Error(glob_av[iu],glob_av2[iu],iblk);
    final.push_back(err_u);
   
     return final;
}




double Error(double sum, double sum2, int iblk)
{
    return sqrt(fabs(sum2/(double)iblk - pow(sum/(double)iblk,2))/(double)iblk);
}


double Gaussiana(double x, double x0, double sigma) {
    return exp(-pow( (x-x0)/sigma, 2.) /2.);
}

double Psi(double x,double sigma, double mu) {
 return Gaussiana(x,mu,sigma) + Gaussiana(x,-mu,sigma);
}
double Psi2(double x,double sigma,double mu){
    return Psi(x,sigma,mu)*Psi(x,sigma,mu) ;
}
double Kinetic(double x, double sigma, double mu) {
    
    double a = (x-mu)*(x-mu)/(sigma*sigma);
    double b = (x+mu)*(x+mu)/(sigma*sigma);
    return 0.5/(sigma*sigma)*( 1. -( a*Gaussiana(x,mu,sigma) + b*Gaussiana(x,-mu,sigma) )/Psi(x,sigma,mu) );
}

double Potenzial(double x) {
    return pow(x,4) -5./2.*pow(x,2);
}
double Hamilton(double x, double sigma,double mu) {
    return Potenzial(x) + Kinetic(x,sigma, mu);
}





/****************************************************************
*****************************************************************
    _/    _/  _/_/_/  _/       Numerical Simulation Laboratory
   _/_/  _/ _/       _/       Physics Department
  _/  _/_/    _/    _/       Universita' degli Studi di Milano
 _/    _/       _/ _/       Prof. D.E. Galli
_/    _/  _/_/_/  _/_/_/_/ email: Davide.Galli@unimi.it
*****************************************************************
*****************************************************************/
