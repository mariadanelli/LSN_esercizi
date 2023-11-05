#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "random.h"

using namespace std;
double error(double mediadelquad, double media, int n) {
	if (n==1) return 0;
	else return sqrt((mediadelquad-pow(media,2))/n);
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
  
int M=10000000;
int N=100;
int L=M/N;

double x1, x2, y2, d=1.5, A=1., theta;
int Nhit=1, Ntot=1;

vector <double> V;
vector <double> Z;


double sommaprog=0;
double sommaprogq=0;

for (int j=0; j<N; j++) {

	double s=0;
    Nhit=1;
    Ntot=1;
  for (int i=0; i<L; i++) {

   x1= rnd.Rannyu(0,d);  //genero casualmente il punto dove cade un'estremità dell'angolo
   
  do {
   x2=rnd.Rannyu(0,1);       //genero casualmente l'angolo con cui cade l'ago
   y2=rnd.Rannyu(0,1);       // utilizzando una x e una y all'interno della circonferenza unitaria, in modo da poter usare il seno e il coseno
   
   }
    while (sqrt((x2)*(x2)+y2*y2)>1. );
   
   theta=atan(y2/x2);

   if (x1+A*cos(theta)>=d)
   Nhit++;
   Ntot++;
	double r=2*A*double(Ntot)/(d*double(Nhit));
	s=s+r;                
	
}
double media=s/L;            // calcolo media nel blocco
double mediaq= pow(media,2); // calcolo la media del quadrato
sommaprog= (media+sommaprog); 
sommaprogq= (mediaq+ sommaprogq);



	
double err=error(sommaprogq/(j+1), sommaprog/(j+1),j+1);
V.push_back(sommaprog/(j+1));     // salvo  media in funzione dei blocchi
Z.push_back(err);    // e il rispettivo errore 
	
}
ofstream out;

out.open("media.dat");
for (int i=0; i<V.size(); i++){
	out<<V[i]<<" "<<Z[i]<<endl;
}
	return 0;
}