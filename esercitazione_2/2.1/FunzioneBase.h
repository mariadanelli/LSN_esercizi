#ifndef __FunzioneBase__
#define __FunzioneBase__
#include <cmath>

class FunzioneBase {
public:
	virtual double Eval(double) const = 0;
	virtual ~FunzioneBase() {
		;
	};
};

class Cos : public FunzioneBase {
public:
	Cos() {
		;
	};
	~Cos() {
		;
	};
	double Eval(double x) const {
		return M_PI/2 *cos(x*M_PI/2);
	};
};


class Funz : public FunzioneBase {
public:
	Funz() {
		;
	};
	~Funz() {
		;
	};
 double Eval(double x) const {
		return 1-sqrt(1-x);
	};
};

class Integranda: public FunzioneBase {
public:
	Integranda() {
		;
	};
	~Integranda() {
		;
	};
 double Eval(double x) const {
		return M_PI/2 *cos(x*M_PI/2)/(2*(1-x));
	};
};
#endif // __FunzioneBase__