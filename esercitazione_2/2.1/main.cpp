#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "random.h"
#include "Integral.h"
#include "FunzioneBase.h"
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
	int N=100;
	int M=1000000;
	int L=M/N;
	double somma=0;
	double sommaprogr=0;
	double sommaprogr2=0;
	Integral I; 
	Cos C;
	double r;
	Funz F;
	vector <double> media; 
	double media1;
	double media2;
	vector <double> errore;
	ofstream out;
		out.open("unif.dat");
	for (int j=0; j<N; j++) {
	 for (int i=0; i<L; i++) {
		 r=rnd.Rannyu();
		somma =somma+ I.IntegraleMedia(r, 100, C);	
	}
		media1=somma/L;
		media2= pow(media1,2);
		sommaprogr= sommaprogr+media1;
		sommaprogr2= sommaprogr2+media2;
		
		somma=0;

	media.push_back(sommaprogr/(j+1));
	errore.push_back(error(sommaprogr2/(j+1), sommaprogr/(j+1), j+1));

		out<<media[j]<<" "<<errore[j]<<endl;
		cout<<media[j]<<" "<<errore[j]<<endl;}

/*importance sampling:
estraggo x che si distribuisce seguendo la distribuzione di prob 2(1-x) e valuto integrale con metodo media */
media.clear();
errore.clear();
   somma=0;
	 sommaprogr=0;
	 sommaprogr2=0;
	media1=0;
	media2=0;
	ofstream out2;
	out2.open("importance.dat");
	Integranda T;
		for (int j=0; j<N; j++) {
	 for (int i=0; i<L; i++) {
		 r=rnd.Rannfunz(F);     //estraggo x che segua la distribuzione di prob pimezzi*(1+ 1/2* pimezzi alla seconda*x^2)  sviluppo di taylor dell'integranda dove 2 è la normalizzazione e (1-x) approssima il coseno 
		somma =somma+ I.IntegraleMedia(r, 100, T);	
	}
		media1=somma/L;
		media2= pow(media1,2);
		sommaprogr= sommaprogr+media1;
		sommaprogr2= sommaprogr2+media2;
		
		somma=0;

	media.push_back(sommaprogr/(j+1));
	errore.push_back(error(sommaprogr2/(j+1), sommaprogr/(j+1), j+1));
			

		out2<<media[j]<<" "<<errore[j]<<endl;
		cout<<media[j]<<" "<<errore[j]<<endl;}

	
	
return 0;}