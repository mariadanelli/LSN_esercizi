#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "random.h"

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
  
int M=1000000;
int N=100;
int L=M/N;


vector <double> V;
vector <double> Z;

vector <double> X;
vector <double> Y;

double sommaprog=0;
double sommaprogq=0;
double sommavar=0;
double sommavarq=0;
for (int j=0; j<N; j++) {
	double s=0;
	double t=0;
  for (int i=0; i<L; i++) {
	double r= rnd.Rannyu();
	s=s+r;                
	t=t+(r-0.5)*(r-0.5);  
}
double varianzam=t/L;         //calcolo media della varianza nel blocco
double varianzamq= pow(varianzam,2);     
double media=s/L;            // calcolo media nel blocco
double mediaq= pow(media,2);
sommaprog= (media+sommaprog); 
sommaprogq= (mediaq+ sommaprogq);
sommavar= sommavar+varianzam;
sommavarq= sommavarq+ varianzamq;


	
double err=error (sommaprogq/(j+1), sommaprog/(j+1),j+1);
V.push_back(sommaprog/(j+1)-0.5);     // salvo quanto dista la media dal valore di aspettazione in funzione dei blocchi
Z.push_back(err);    // e il rispettivo errore 

double err2=error (sommavarq/(j+1), sommavar/(j+1),j+1);    //stesso procedimento ma con la varianza 
X.push_back(sommavar/(j+1)-1./12.);
Y.push_back(err2);
	}

ofstream out;
ofstream out2;
out.open("media.dat");
out2.open ("varianza.dat");
for (int i=0; i<V.size(); i++){
	out<<V[i]<<" "<<Z[i]<<endl;
}
for (int i=0; i<X.size(); i++){
	out2<<X[i]<<" "<<Y[i]<<endl;
}

	
/*test del chi quad*/
	
int inter=100;
int punti=10000; 
vector <double> C;
ofstream out3;
out3.open("chiq.dat");
	
for (int j=0; j<100; j++)  {
	 double chiq=0;
   vector <int> k (inter,0);
 for (int i=0; i<punti; i++) {
	double x= rnd.Rannyu();
	int j= x*inter;
	k[j]++;
	}
	
	for (int i=0; i< inter; i++) {
	chiq= chiq+ (pow((k[i]- (punti/inter)),2)/(punti/inter));
		}

	C.push_back(chiq); 
	out3<<chiq<<endl;}

out3.close();

	return 0;
}