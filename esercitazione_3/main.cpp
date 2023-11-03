#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "random.h"
#include "funzioni.h"
#include <vector>
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

	
double S0=100;
double S=S0;
double r=0.1;
double sigma=0.25;
double K=100;
double T=1;
double C=0;
double P=0;
	
  
int M=1000000;
int N=100;
int L=M/N;

vector <double> V;
vector <double> Z;
vector <double> X;
vector <double> Y;

	
double sommaprog=0;
double sommaprog2=0;
double sommaprogq2=0;
double sommaprogq=0;

ofstream out; 
out.open("direttoC.dat");


ofstream out2; 
out2.open("direttoP.dat");

/*calcolo C  e P in modo discreto*/
	/*vector <double> C1;
	vector <double> P1;
for (int i=0; i<M; i++) {
	double z=rnd.Gauss(0,1);
	S=S0*exp((r-0.5*sigma*sigma)*T+sigma*z*sqrt(T));
	C=exp(-r/T)*max(0, S-K);
	P=exp(-r/T)*max(0, K-S);
	C1.push_back(C);
	P1.push_back(P);
}	

vector<vector<double>> X=MediaBlocchi(M, N, C1);
		cout<<"cia0"<<endl;
vector<vector<double>> Y=MediaBlocchi(M, N, P1);
	cout<<"ciao again"<<endl;
ofstream out1;
ofstream out2;
out1.open("prova.dat");
out2.open ("prova2.dat");
	cout<<X.size()<<endl;
for (int i=0; i<N; i++) {
out1<<X[1][i]<<" "<<X[2][i]<<endl;
out2<<Y[1][i]<<" "<<Y[2][i]<<endl;
	}
	cout<<"sto per finire"<<endl;*/

	
for (int j=0; j<N; j++) {
double somma=0;
double somma2=0;
  for (int i=0; i<L; i++) {

	double z=rnd.Gauss(0,1);
	S=S0*exp((r-0.5*sigma*sigma)*T+sigma*z*sqrt(T));
	C=exp(-r/T)*max(0, S-K);
	P=exp(-r/T)*max(0, K-S);

		somma=C+somma;
		somma2=P+somma2;
}
double media=somma/L;
double mediaq= pow(media,2);
sommaprog= (media+sommaprog); 
sommaprogq= (mediaq+ sommaprogq);

double media2=somma2/L;
double mediaq2= pow(media2,2);
sommaprog2= (media2+sommaprog2); 
sommaprogq2= (mediaq2+ sommaprogq2);

	
double err=error (sommaprogq/(j+1), sommaprog/(j+1),j+1);
V.push_back(sommaprog/(j+1));
Z.push_back(err);

double err2=error (sommaprogq2/(j+1), sommaprog2/(j+1),j+1);
X.push_back(sommaprog2/(j+1));
Y.push_back(err2);
out<<V[j]<<" "<<Z[j]<<endl;
out2<<X[j]<<" "<<Y[j]<<endl;
	}






sommaprog=0;
sommaprogq=0;
sommaprog2=0;
sommaprogq2=0;	
int npassi=100;
double passo=T/100.;
vector <double> R;
vector <double> W;
vector <double> U;
vector <double> E;
	
for (int j=0; j<N; j++) {
double somma=0;
double somma2=0;
  for (int i=0; i<L; i++) {

	S=S0;
		for(int k=0; k<npassi; k++){	
			double z=rnd.Gauss(0,1);
				S = S*exp((r-0.5*sigma*sigma)*passo + sigma*z*sqrt(passo));
			}
		
			C=exp(-r/T)*max(0, S-K);
	    P=exp(-r/T)*max(0, K-S);
		somma=C+somma;
		somma2=P+somma2;
}
double media=somma/L;

double mediaq= pow(media,2);
sommaprog= (media+sommaprog); 
sommaprogq= (mediaq+ sommaprogq);

double media2=somma2/L;

double mediaq2= pow(media2,2);
sommaprog2= (media2+sommaprog2); 
sommaprogq2= (mediaq2+ sommaprogq2);


double err=error (sommaprogq/(j+1), sommaprog/(j+1),j+1);
R.push_back(sommaprog/(j+1));
W.push_back(err);

	
double err2=error (sommaprogq2/(j+1), sommaprog2/(j+1),j+1);
U.push_back(sommaprog2/(j+1));
E.push_back(err2);

	}

ofstream out3; 
out3.open("discretizzatoC.dat");

for (int i=0; i<R.size(); i++){
	out3<<R[i]<<" "<<W[i]<<endl;
}

ofstream out4; 
out4.open("discretizzatoP.dat");

for (int i=0; i<U.size(); i++){
	out4<<U[i]<<" "<<E[i]<<endl;
}

	rnd.SaveSeed();
	return 0;

}