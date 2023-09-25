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
double somma[passi]= {0};
double somma2[passi];
double media[passi];
double media2[passi];
double dist[passi];
double sommaprogr[passi]={0};
double sommaprogr2[passi];
int N=100;
int M=100000;
int L= M/N;

out.open("randomwalkdiscreto.dat");

/*ripeto l'operazione 100000 volte 
discreto*/

 for (int z=0; z<N; z++) {
	
  for (int j=0; j<L; j++) {
      Posizione P; 
			for (int i= 0; i<passi; i++) { 
              r=rnd.Rannyu();	
				
	         if (r<1./6.) { P.Setx(P.Getx()+a);}
	         if ((r>1./6.) && (r<2./6.)) {P.Setx(P.Getx()-a);}
	         if ((r>2./6.) && (r<3./6.)) {P.Sety(P.Gety()+a);}
	         if ((r>3./6.) && (r<4./6.)) {P.Sety(P.Gety()-a);}
	         if ((r> 4./6.) && (r<5./6.)) {P.Setz(P.Getz()+a);}
	         if ((r>5./6.) && (r<6./6.)) {P.Setz(P.Getz()-a);}
	           dist[i]= P.GetR(); }
		
            for (int i= 0; i<passi; i++) {
	         somma[i]=dist[i]+ somma[i]; 
             media[i]= somma[i]/L;
	         media2[i]= media[i]*media[i]; }
				
  }   
                       
             for (int i= 0; i<passi; i++) {
  sommaprogr[i]= sommaprogr[i]+media[i];
  sommaprogr2[i]= sommaprogr2[i]+media2[i];
	somma[i]=0;	}
  }
		
	
	for (int i= 0; i<passi; i++) {
	 out<<sommaprogr[i]/N<<" "<<error(sommaprogr2[i]/N, sommaprogr[i]/N, N)<<endl;
	 sommaprogr[i]=0;
	 sommaprogr2[i]=0; }
      
	
out.close();
/*continuo*/
ofstream out2;
out2.open("randomwalkcontinuo.dat");
double theta;
double phi;
for (int z=0; z<N; z++) {
	
  for (int j=0; j<L; j++) {
      Posizione P; 
			 for (int i= 0; i<passi; i++) {
                 phi=rnd.Rannyu(0,M_PI);	
				 theta=rnd.Rannyu(0,2*M_PI);
				     P.Setx(P.Getx()+a*cos(theta)*cos(phi));
				     P.Sety(P.Gety()+a*sin(theta)*cos(phi));
				     P.Setz(P.Getz()+a*cos(phi));
	        	        
	             dist[i]= P.GetR();
				 }
		
			  for (int i= 0; i<passi; i++) {
	           somma[i]=dist[i]+ somma[i]; 
				media[i]= somma[i]/L;
	    media2[i]= media[i]*media[i]; }
			} 
	
		
		
   for (int i= 0; i<passi; i++) {
  sommaprogr[i]= sommaprogr[i]+media[i];
  sommaprogr2[i]= sommaprogr2[i]+media2[i];
		somma[i]=0; } 
         }
	
 for (int i= 0; i<passi; i++) {
	 out2<<sommaprogr[i]/N<<" "<<error(sommaprogr2[i]/N, sommaprogr[i]/N, N)<<endl;}

return 0;
          }