#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "random.h"
#include "Posizione.h"
using namespace std;

double error(double mediadelquad, double media, int n) {
	if (n==0) return 0;
	else return sqrt((mediadelquad- pow(media,2))/n);
};


int main (int argc, char *argv[]){
   Random rnd;
   int seed[4];
   int p1, p2;
   ifstream Primes("Primes");
   if (Primes.is_open()){
      Primes >> p1 >> p2 ;
   } else cerr << "PROBLEM: Unable to open Primes" << endl;
   Primes.close();

   ifstream input("seed.in");
   string property;
   if (input.is_open()){
      while ( !input.eof() ){
         input >> property;
         if( property == "RANDOMSEED" ){
            input >> seed[0] >> seed[1] >> seed[2] >> seed[3];
            rnd.SetRandom(seed,p1,p2);
         }
      }
      input.close();
   } else cerr << "PROBLEM: Unable to open seed.in" << endl;

   rnd.SaveSeed();
	
int passi=100;
int a=1;

ofstream out;
double r;
double somma[100]= {0};

double media[100];
double media2[100];
double dist[100]={0};
double sommaprogr[100]={0};
double sommaprogr2[100];
int N=100;
int M=100000;
int L= M/N;

out.open("randomwalkdiscreto.dat");

/*ripeto l'operazione 100000 volte 
discreto*/

Posizione P;


for (int i= 0; i<passi; i++) { 

     

  for (int z=0; z<N; z++) {
	 
    for (int j=0; j<L; j++) {
        P.Setx(0.);
		  P.Sety(0.);
		  P.Setz(0.);

            for (int p= 0; p<i; p++) { 
              r=rnd.Rannyu();	 
				
	         if (r<1./6.) { P.Setx(P.Getx()+a);}
	         if ((r>=1./6.) && (r<2./6.)) {P.Setx(P.Getx()-a);}
	         if ((r>=2./6.) && (r<3./6.)) {P.Sety(P.Gety()+a);}
	         if ((r>=3./6.) && (r<4./6.)) {P.Sety(P.Gety()-a);}
	         if ((r>= 4./6.) && (r<5./6.)) {P.Setz(P.Getz()+a);}
	         if ((r>= 5./6.) && (r<6./6.)) {P.Setz(P.Getz()-a);} }

	          

	         somma[i]= somma[i]+ pow(P.GetR(),2);}
             media[i]= somma[i]/L;
	         media2[i]= media[i]* media[i]; 
  
   
  sommaprogr[i]= sommaprogr[i]+media[i];
  sommaprogr2[i]= sommaprogr2[i]+media2[i];
		somma[i]=0; 
  }

	 out<<sqrt(sommaprogr[i]/(N+1))<<" "<<error(sqrt(sommaprogr2[i]/(N+1)), sqrt(sommaprogr[i]/(N+1)),N+1)<<endl;
    sommaprogr2[i]=0;
sommaprogr[i]=0;

}

      
	
out.close();
/*continuo*/
ofstream out2; 
out2.open("randomwalkcontinuo.dat");
double theta;
double phi;

for (int i= 0; i<passi; i++) {
 for (int z=0; z<N; z++) {
	
  for (int j=0; j<L; j++) {
        P.Setx(0.);
		  P.Sety(0.);
		  P.Setz(0.);

            for (int p= 0; p<i; p++) { 
     	
                 phi=rnd.Rannyu(0,M_PI);	
				     theta=rnd.Rannyu(0,2*M_PI);

				     P.Setx(P.Getx()+a*cos(theta)*sin(phi));
				     P.Sety(P.Gety()+a*sin(theta)*sin(phi));
				     P.Setz(P.Getz()+a*cos(phi));}
	        	        
	             dist[i]= pow(P.GetR(),2);
				 
	           somma[i]=dist[i]+ somma[i]; }

				media[i]= somma[i]/L;
	         media2[i]= media[i]*media[i]; 			
	 cout<<z<<endl;
  sommaprogr[i]= sommaprogr[i]+media[i];
  sommaprogr2[i]= sommaprogr2[i]+media2[i];
		somma[i]=0; } 
     
	 out2<<sqrt(sommaprogr[i]/(N+1))<<" "<<error(sqrt(sommaprogr2[i]/(N+1)), sqrt(sommaprogr[i]/(N+1)), (N+1))<<endl; 
    }
    

return 0;
          }