#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "random.h"

using namespace std;

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
int M=10000;
int N;
double s=0;


	ofstream out1;
	ofstream out2;
	ofstream out10;
	ofstream out100;

	out1.open ("uno");
	out2.open ("due");
	out10.open ("dieci");
	out100.open ("cento");
	N=1;
 for (int i=0; i<M; i++) {
	 s=0;
	 for (int j=0; j<N; j++) {
	 double r= rnd.Rannyu();
	 s=r+s;
 }
	out1<<(s/N)<<endl ;
	 }

N=2;
 for (int i=0; i<M; i++) {
	 s=0;
	 for (int j=0; j<N; j++) {
	 double r= rnd.Rannyu();
	 s=r+s;
		
 }
	  out2<<(s/N)<<endl ;

	 }

N=10;
	 for (int i=0; i<M;i++) {
		 s=0;
	 for (int j=0; j<N; j++) {
	 double r= rnd.Rannyu();
	 s=r+s;
		
 }
		  out10<<(s/N)<<endl ;

	
	 }

N=100;

 for (int i=0; i<M; i++) {
	 s=0;
	 for (int j=0; j<N; j++) {
	 double r= rnd.Rannyu();
	 s=r+s;
		 
 }
	 out100<<(s/N)<<endl ;

	 }
	return 0;
	}