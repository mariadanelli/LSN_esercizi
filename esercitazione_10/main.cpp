#include <mpi.h>
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

int main (int argc, char* argv []) {

    int size, rank;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);




Input();

// preparo le posizioni delle città

Posizione citta[N_cities];

ifstream in;
in.open("American_capitals.dat");
if (in.is_open()) {
string k, z, m, n; 
double x, y;
in>>k>>z>>m>>n;
for (int i=0; i<N_cities; i++ ) {
in>>k>>z>>x>>y;
citta[i].Setx(x);
citta[i].Sety(y);
}}
else {cout<<"ops"; return 1;}

in.close();


Inizializzazione(rnd, rank);
Individuo I= CreaIndividuo();






if (migra==1) {

ofstream out;
ofstream outb;
out.open("L" + to_string(rank)+ to_string(migra)+".dat");
outb.open("bestgen" + to_string(rank) +to_string(migra)+".dat");
ofstream b;
b.open("best" + to_string(rank)+to_string(migra)+".dat");

//creo popolazione di partenza 

Popolazione Pop = CreaPopolazione(N_pop);
// Pop.Print(citta);
Ordina(Pop, citta); //ordino dal piu lungo al piu breve 





        Popolazione newPop;
        Individuo genitore1;
        Individuo genitore2;
        for (int i=0; i<N_pop; i++) {
        do {
            genitore1= Selection(Pop,r);
            genitore2= Selection(Pop,r);
        if (rnd.Rannyu() < pc) {
        Crossover(genitore1, genitore2);}

        Mutation2(genitore1);
        Mutation2(genitore1);} while((genitore1.check()==false) || (genitore2.check()==false));

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
            genitore1= Selection(newPop, r);
            genitore2= Selection(newPop,r);
        if (rnd.Rannyu() < pc) {
        Crossover(genitore1, genitore2);}
        Mutation2(genitore1);
        Mutation2(genitore1);} while((genitore1.check()==false) || (genitore2.check()==false));
      
        newPop.Set(i,genitore1);
        newPop.Set(i+1,genitore2);
        i=i+1;
        }

        Ordina(newPop, citta);
        outb<<newPop.Get(N_pop-1).Costo(citta)<<endl;
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

}


else {

ofstream out;
ofstream outb;
out.open("L" + to_string(rank)+ to_string(migra)+".dat");
outb.open("bestgen" + to_string(rank) +to_string(migra)+".dat");
ofstream b;
b.open("best" + to_string(rank)+to_string(migra)+".dat");

//creo popolazione di partenza 

Popolazione Pop = CreaPopolazione(N_pop);
// Pop.Print(citta);
Ordina(Pop, citta); //ordino dal piu lungo al piu breve 





        Popolazione newPop;
        Individuo genitore1;
        Individuo genitore2;
        for (int i=0; i<N_pop; i++) {
        do {
            genitore1= Selection(Pop,r);
            genitore2= Selection(Pop,r);
        if (rnd.Rannyu() < pc) {
        Crossover(genitore1, genitore2);}

        Mutation2(genitore1);
        Mutation2(genitore1);} while((genitore1.check()==false) || (genitore2.check()==false));

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
            genitore1= Selection(newPop, r);
            genitore2= Selection(newPop,r);
        if (rnd.Rannyu() < pc) {
        Crossover(genitore1, genitore2);}
        Mutation2(genitore1);
        Mutation2(genitore1);} while((genitore1.check()==false) || (genitore2.check()==false));
      
        newPop.Set(i,genitore1);
        newPop.Set(i+1,genitore2);
        i=i+1;
        }

        Ordina(newPop, citta);
        outb<<newPop.Get(N_pop-1).Costo(citta)<<endl;
        double s=0;
        for (int i=N_pop/2.; i<N_pop; i++) {
            s=newPop.Get(i).Costo(citta)+s;
    
        }
        s=s/(double(N_pop)/2.);
        out<<s<<endl;
if ((k % N_mig )==0)
{

MPI_Status stat;
cout<<rank<<" "; 
newPop.Get(N_pop-1).Print();
Individuo I= newPop.Get(N_pop-1);
I.Print();
for (int i=1; i<N_cities; i++) {
int itag=0;

int imesg =newPop.Get(N_pop-1).Get(i);

if(rank!=3) {
MPI_Send(&imesg,1,MPI_INT,rank+1,itag,MPI_COMM_WORLD); }
else if(rank==3) {
MPI_Send(&imesg,1,MPI_INT,rank-3,itag,MPI_COMM_WORLD); }


if (rank!= 0) {
MPI_Recv(&imesg,1,MPI_INT,rank-1,itag,MPI_COMM_WORLD,
&stat);}
else if(rank==0) {
MPI_Recv(&imesg,1,MPI_INT,rank+3,itag,MPI_COMM_WORLD,
&stat); }



cout<<rank<< " "<<imesg<<endl;

SetReal(I, i, imesg); 

}
I.Print();
if (I.check()==false) cout<<"aa"<<endl;
newPop.Get(N_pop-1).Print(); 
newPop.Set(N_pop-1, I);
cout<<"ei"<<rank<<" ";

newPop.Get(N_pop-1).Print(); 
 }

        if (k==N_gen-1) {
            int l;
            for (int i=0; i<N_cities; i++) {
            if ( newPop.Get(N_pop-1).check()==false)  cout<<"cazzo"<<endl;
             newPop.Get(N_pop-1).Print();
             l= newPop.Get(N_pop-1).Get(i); 
             b<<citta[l].Getx()<<"    "<<citta[l].Gety()<<endl;
            }
        }


}
// if(rank!=3) {
 /*   for (int i=0; i<N_cities; i++) {
        cout<<"oo"<<endl;
        int imesg = newPop.Get(999).Get(i);
        cout<<i<<endl;
MPI_Send(&imesg,rank,MPI_INT,rank+1,itag,MPI_COMM_WORLD); // argomento: messaggio, numero di messaggi, tipo di mess da inviare, a chi lo mando, etichett
MPI_Recv(&imesg,rank+1,MPI_INT,rank,itag,MPI_COMM_WORLD,
&stat); 
newPop.Get(999).Set(i, imesg );
cout<<i<<" ei 2"<<endl;
 }   */ 
     //  } 

/*if(rank==3) 
     {
         
        int imesg = newPop.Get(999).Get(i);
MPI_Send(&imesg,3,MPI_INT,0,itag,MPI_COMM_WORLD); // argomento: messaggio, numero di messaggi, tipo di mess da inviare, a chi lo mando, etichett
MPI_Recv(&imesg,0,MPI_INT,3,itag,MPI_COMM_WORLD, &stat);
}  
       } 
       cout<<rank<<endl;
       newPop.Get(999).Print();
    }
}
} 
/*
int itag=1;
int imesg = rank;
if(rank==1)
MPI_Send(&imesg,1,MPI_INT,0,itag,MPI_COMM_WORLD); // argomento: messaggio, numero di messaggi, tipo di mess da inviare, a chi lo mando, etichetta
else if(rank==0)
MPI_Recv(&imesg,1,MPI_INT,1,itag,MPI_COMM_WORLD,
&stat);
*/
}
   cout<<" Sono il nodo "<<rank<<" dei "<<size<<" che hai utilizzato!"<<endl;
    MPI_Finalize();
    return 0; }


