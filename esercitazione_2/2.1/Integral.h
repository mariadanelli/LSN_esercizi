#ifndef __Integral__
#define __Integral__
#include <cmath>
#include "FunzioneBase.h"
#include "random.h"

class Integral {
public:Integral () {m_R= new Random();};
	~Integral(){;};


double IntegraleMedia(double x, int passi, FunzioneBase &f) {

		double somma=0;
	for (int i=0; i<passi; i++) {
		somma= somma+f.Eval(x);
	   
	}
return somma/double(passi);}
private: Random *m_R;
};

#endif 