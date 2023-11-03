#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "funzioni.h"
#include <vector>

using namespace std;


double error(double mediadelquad, double media, int n) {
	if (n==0) return 0;
	else return sqrt((mediadelquad- pow(media,2))/n);
};

double max(double x1, double x2) {
	if (x1>x2) return x1;
	if (x1<x2) return x2;
	else { cout<<"attenzione sono uguali"<<endl;
		return 0;
}
	}

/*vector<vector<double>> MediaBlocchi (int M, int N, vector <double> r) {
	
double sommaprog=0;
double sommaprogq=0;
vector<vector<double>> X(N,vector<vector<double>>(2));
for (int j=0; j<N; j++) {
double somma=0;

  for (int i=j; i<j+M/N; i++) {
		somma=r[i]+somma;
}
	
double media=somma/(M/N);
double mediaq= pow(media,2);
sommaprog= (media+sommaprog); 
sommaprogq= (mediaq+ sommaprogq);

X[1][j]=(sommaprog/(j+1));
	cout<<sommaprog/(j+1)<<endl;
X[2][j]=(error (sommaprogq/(j+1), sommaprog/(j+1),j+1));

}
	return X;
	};
*/