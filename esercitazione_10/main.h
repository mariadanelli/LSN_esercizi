#include "../random.h"
#include "Posizione.h"
#include <cstdlib> 

using namespace std;

Random rnd;
static const int N_pop=1000;
static const int N_cities=50; 
double pc, pc2=0.9, r;
int N_gen, N_gen2=200, migra, N_mig;


void Inizializzazione (Random &rnd, int rank){
   int seed[4];
   int p1, p2, t,s;
   ifstream Primes("../Primes");
   if (Primes.is_open()){
     Primes>>t>>s;
      for (int i=0; i<2*rank+1; i++) {
      Primes >> t>>s; }
      Primes >> p1 >> p2 ;
      
   } else cerr << "PROBLEM: Unable to open Primes" << endl;
   Primes.close();

   ifstream input("../seed.in");
   string property;
   if (input.is_open()){
      while ( !input.eof() ){
         input >> property;
         if( property == "RANDOMSEED" ){
            input >> seed[0] >> seed[1] >> seed[2] >> seed[3];
             seed[3]+=rank;
            rnd.SetRandom(seed,p1,p2);
         }
      }
      input.close();
   } else cerr << "PROBLEM: Unable to open seed.in" << endl;
}



  void Input(void)
{

ifstream ReadInput;
ReadInput.open("input.in");

  ReadInput >> r;

  ReadInput >> pc;

  ReadInput >> N_gen;

  ReadInput>> N_mig;

  ReadInput >> migra;

  ReadInput.close();

  return;
}



struct Individuo {

    int Ind[N_cities] ;
   
    int Get(int i){return Ind[i]; };

    void Set(int i, int j) {Ind[i]=j; }; //attenzione ad utilizzarlo fuori da funzioni

    void Print() {
        for (int i=0; i<N_cities; i++) {
            cout<<Ind[i]<<" ";
        }
        cout<<endl;
        return;
    }; 
   
    bool check() {
     
    /*    double s=0;
        double k=0;
        double 

     for (int i=0; i<N_cities; i++) {
      s=s+i*i;
      k=k+ Ind[i]*Ind[i];
      
      } 
cout<<s<<" "<<k<<endl;
     if (s!=k) {
     return false;
     }
    
    return true;
    };*/
       for(int i = 0; i < N_cities; i++) {
            for(int j = i+1; j < N_cities; j++) {
                if(Ind[i] == Ind[j]){
                   return false;
                }
            } 
       }
                return true; };


    double Costo(Posizione citta[N_cities]) {
       double L=0;
    for (int k=1; k<N_cities; k++) {
    int i= Ind[k];
    int j= Ind[k-1];
    L= L+citta[i].Distanza(citta[j]);
    }

    L= L+citta[0].Distanza(citta[N_cities-1]);
    return L;
    } ;
};

void SetReal (Individuo& Ind, int pos, int i) {
   Ind.Set(pos, i);   
};

void ScambioCasuale (Individuo& Ind) {
    int i, j;
    int pos=int(rnd.Rannyu(1.,N_cities-1));
    int pos2;
     do {pos2=int(rnd.Rannyu(1.,N_cities-1));  } while (pos==pos2);
     i = Ind.Get(pos); 
     j = Ind.Get(pos2); 
     Ind.Set(pos, j);   
     Ind.Set(pos2, i);
   
    };   



void Scambio (Individuo& Ind, int pos, int pos2) {
    int i, j;
     i = Ind.Get(pos); 
     j = Ind.Get(pos2); 
     Ind.Set(pos, j);   
     Ind.Set(pos2, i);
    };  

int pbc(int x) {
    if (x<N_cities) return x;
    else return x%N_cities+1;
}

void Shift (Individuo& Ind) {
   
    int m= int(rnd.Rannyu(1.,N_cities));
    int x= int(rnd.Rannyu(1.,N_cities));
    int n=  int(rnd.Rannyu(1.,N_cities));
  
    /*for (int i=0; i<N_cities; i++) {
     IndCopia[i]= Ind.Get(i);}
    for (int i=x; i<x+m; i++) {
   Ind.Set(pbc(i+n),IndCopia[pbc(i)]);
   cout<<n<<i<<"  "<<IndCopia[pbc(i)]<<"  "<<Ind.Get(pbc(i))<<endl;*/
    for (int i=x; i<x+m; i++) { 
        Scambio(Ind, pbc(i), pbc(i+n));
}
}

void Permut (Individuo& Ind) {
   
    int m= int(rnd.Rannyu(1.,N_cities/2));
    int x= int(rnd.Rannyu(1.,N_cities));
    for (int i=x; i<x+m; i++) { 
        Scambio(Ind, pbc(i), pbc(i+m));
}
}

void Invers (Individuo& Ind) {
   
    int m= int(rnd.Rannyu(1.,N_cities/2));
    int x= int(rnd.Rannyu(1.,N_cities));
    int j=m-1;
    for (int i=x; i<x+int(double(m)/2); i++) { 
        
        Scambio(Ind, pbc(i), pbc(i+j));
      
        j=j-2;
}
}


Individuo CreaIndividuo () {
    int k=0;
    Individuo Ind;
    for (int i=1; i<N_cities; i++) { 
        do {k=0;
            Ind.Set(i,int(rnd.Rannyu(1.,N_cities)));
           
            for (int j=0; j<i; j++) {
                if (Ind.Get(i) != Ind.Get(j) /*&& Ind.Get(i)!= hometown*/  ) 
                  k++;
            } 
        } while (k!=i);             // attenzione  hometown=0
    }
    Ind.Set(0, 0);
    return Ind;
} ; 



struct Popolazione {
    Individuo Pop[N_pop];
    void Set(int i, Individuo I) {Pop[i]= I;};
    Individuo Get (int i) {return Pop[i];};
    void Print (Posizione citta[N_cities]) {
        for (int i=0; i<N_pop; i++) {
        Pop[i].Print(); cout<<Pop[i].Costo(citta)<<"  "<<i<<endl;};
                  };
    bool check() { 
        for (int i=0; i<N_pop; i++) {
            if (Pop[i].check()==false) { cout<<i<<endl;return false;
        }
        }
        return true;
    };
} ;

Popolazione CreaPopolazione (int Npop) {
   Popolazione Pop;
   Individuo I;
   do { I = CreaIndividuo();
       Pop.Set(0,I);} while (I.check()==false);
   for (int i=1; i<Npop; i++) { 
      do { ScambioCasuale(I);
       Pop.Set(i,I);} while (I.check()== false);
    }
    /*for (int i=0; i<Npop; i++) { 
       Individuo I = CreaIndividuo();
       Pop.Set(i,I);
    }*/
    return Pop;
} ; 

void Scambio (Popolazione& pop, int pos, int pos2) {
    Individuo i, j;
     i = pop.Get(pos); 
     j = pop.Get(pos2); 
     pop.Set(pos, j);   
     pop.Set(pos2, i);
    }; 


void Ordina (Popolazione& Pop, Posizione citta[N_cities]) {
    double Dist[N_pop];
    Individuo I;
    int k;
    double c;
    for (int i=0; i<N_pop; i++) {
        for (int j=i; j<N_pop; j++) {
            if (Pop.Get(j).Costo(citta)>Pop.Get(i).Costo(citta))
     Scambio(Pop,i,j);
        }
    } 
}

Individuo Selection (Popolazione& Pop, double p) {
    int j= int((N_pop*pow(rnd.Rannyu(),p)));

    return Pop.Get(j); 
}


void Crossover (Individuo& genitore1, Individuo& genitore2) {
    int cut= rnd.Rannyu(0,N_cities);
    Individuo copia;
    for (int i=0; i<N_cities; i++) {copia.Set(i,genitore1.Get(i));}
    for (int i= cut; i<N_cities; i++) {
        genitore1.Set(i,genitore2.Get(i));
        genitore2.Set(i,copia.Get(i));
        
    }
}

void Mutation2(Individuo& I) {
  double p= rnd.Rannyu(0,10);
   if (p<2.1) ScambioCasuale(I);
   if (p>=2.1 && p<3.2) Shift(I);
   if (p>=3.2 && p<4.3) Invers(I);
   if (p>=4.3 && p<5.4) Permut(I);
}

void Mutation(Individuo& I) {
  double p= rnd.Rannyu(0,10);
   if (p<1.5) ScambioCasuale(I);
   if (p>=1.5 && p<3.0) Shift(I);
   if (p>=3.0 && p<4.5) Invers(I);
   if (p>=4.5 && p<6.0) Permut(I);
}