#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "../random.h"
#include "Posizione.h"
#include "main.h"


using namespace std;


int main() {

Inizializzazione(rnd);


// preparo le 34 città lungo la circonferenza

Posizione citta[N_cities];
int k=0;
ofstream cer;
cer.open("Disposizionecerchio.dat");

for (int i=0; i<N_cities; i++ ) {

double theta= rnd.Rannyu(0,2*M_PI);

do { k=0;
  for (int j=0; j<i; j++) {
if (citta[i].Getx() != citta[j].Getx () || citta[i].Gety() != citta[j].Gety() )
k++; 
}
} while (k!=i);
citta[i].Setx(cos(theta));
citta[i].Sety(sin(theta)); 
cer<<cos(theta)<<"   "<<sin(theta)<<endl;
}



 Posizione citta2[N_cities];
 ofstream quad;
 quad.open("Disposizionequadrato.dat");
double x;
double y;
for (int i=0; i<34; i++ ) {

do { k=0;
x=rnd.Rannyu(-1.,1.);
y=rnd.Rannyu(-1.,1.);
  for (int j=0; j<i; j++) {
if (citta2[i].Getx() != citta2[j].Getx () || citta2[i].Gety() != citta2[j].Gety() )
k++; 
}
} while (k!=i);

citta2[i].Setx(x);
citta2[i].Sety(y); 
quad<<x<<"  "<<y<<endl;
}





ofstream out;
ofstream outb;
out.open("cerchioL2.dat");
outb.open("bestgencir.dat");
ofstream b;
b.open("best.dat");
//creo popolazione di partenza 

Popolazione Pop = CreaPopolazione(N_pop);
// Pop.Print(citta);
Ordina(Pop, citta); //ordino dal piu lungo al piu breve 





        Popolazione newPop;
        Individuo genitore1;
        Individuo genitore2;
        for (int i=0; i<N_pop; i++) {
        do {
            genitore1= Selection(Pop,0.08);
            genitore2= Selection(Pop,0.08);
        if (rnd.Rannyu() < pc) {
        Crossover(genitore1, genitore2);}
        Mutation(genitore1);
        Mutation(genitore1);} while((genitore1.check()==false) || (genitore2.check()==false));

        newPop.Set(i,genitore1);
        newPop.Set(i+1,genitore2);
        i=i+1;
        }
        Ordina(newPop, citta);
   


   for (int k=0; k<N_gen; k++) { 

       Individuo genitore1;
       Individuo genitore2;
        for (int i=0; i<N_pop; i++) {
        do {
            genitore1= Selection(newPop, 0.08);
            genitore2= Selection(newPop, 0.08);
        if (rnd.Rannyu() < pc) {
        Crossover(genitore1, genitore2);}
        Mutation(genitore1);
        Mutation(genitore1);} while((genitore1.check()==false) || (genitore2.check()==false));

        newPop.Set(i,genitore1);
        newPop.Set(i+1,genitore2);
        i=i+1;
        }

        Ordina(newPop, citta);
        outb<<newPop.Get(999).Costo(citta)<<endl;
        double s=0;
        for (int i=N_pop/2.; i<N_pop; i++) {
            s=newPop.Get(i).Costo(citta)+s;
    
        }
        s=s/(double(N_pop)/2.);
        out<<s<<endl;

        if (k==N_gen-1) {
            int l;
            for (int i=0; i<N_cities; i++) {
             l= newPop.Get(N_pop-1).Get(i); 
             b<<citta[l].Getx()<<"    "<<citta[l].Gety()<<endl;
            }
        }
}









// situa nel quadrato



ofstream out2;
ofstream b2;
ofstream outb2;

out2.open("quadratoL2.dat");
b2.open("bestquad.dat");
outb2.open("bestgenquad.dat");
//creo popolazione di partenza 

Popolazione Pop2 = CreaPopolazione(N_pop);

Ordina(Pop2, citta2); //ordino dal piu lungo al piu breve 





        Popolazione newPop2;

        for (int i=0; i<N_pop; i++) {
        do {
            genitore1= Selection(Pop2,0.1);
            genitore2= Selection(Pop2,0.1);
        if (rnd.Rannyu() < pc2) {
        Crossover(genitore1, genitore2);}
        Mutation2(genitore1);
        Mutation2(genitore1);} while((genitore1.check()==false) || (genitore2.check()==false));

        newPop2.Set(i,genitore1);
        newPop2.Set(i+1,genitore2);
        i=i+1;
        }
        Ordina(newPop2, citta2);
   


   for (int k=0; k<N_gen2; k++) { 

       Individuo genitore1;
       Individuo genitore2;
        for (int i=0; i<N_pop; i++) {
        do {
            genitore1= Selection(newPop2, 0.1);
            genitore2= Selection(newPop2, 0.1);
        if (rnd.Rannyu() < pc) {
        Crossover(genitore1, genitore2);}
        Mutation2(genitore1);
        Mutation2(genitore1);} while((genitore1.check()==false) || (genitore2.check()==false));

        newPop2.Set(i,genitore1);
        newPop2.Set(i+1,genitore2);
        i=i+1;
        }
        Ordina(newPop2, citta2);
        outb2<<newPop2.Get(999).Costo(citta2)<<endl;
      
        // newPop2.Print(citta2);
        double s=0;
        for (int i=N_pop/2.; i<N_pop; i++) {
            s=newPop2.Get(i).Costo(citta2)+s;
        }

        s=s/(double(N_pop)/2.);
        out2<<s<<endl;
    
        if (k==N_gen2-1) {
            int l;
            for (int i=0; i<N_cities; i++) {
             l= newPop2.Get(N_pop-1).Get(i); 
             b2<<citta2[l].Getx()<<"    "<<citta2[l].Gety()<<endl;}
}
   }



  return 0;
}


