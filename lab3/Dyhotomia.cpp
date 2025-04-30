#include "Dyhotomia.h"

Dyhotomia::Dyhotomia(void) {}

Dyhotomia::~Dyhotomia(void) {}

void Dyhotomia::setVolumes(double vol_a, double vol_b) {
	a = vol_a;
	b = vol_b;
}

void Dyhotomia::setTolerance(double vol_eps) {
	eps = vol_eps;
}

double Dyhotomia::halfdyh(void) {
	return (a + b) / 2;
}

double Dyhotomia::funcbigger(double a, double b) {
	double fa = 3*sin(sqrt(a)) + 0.35*a - 3.8;
	std::cout << "f(a) = " << fa << "    a = " << a << "\n";
	double fb =  3*sin(sqrt(b)) + 0.35*b - 3.8;
	std::cout << "f(b) = " << fb << "    b = " << b << "\n";
	return fa * fb;
}

double Dyhotomia::solution(void) {
	if (funcbigger(a, b) > 0) {
		std::cout << "No roots";
		return 1;
	}
	do {
		double c = halfdyh();

		if (funcbigger(a, c) < 0) {
			b = c;
		}
		else {
			a = c;
		}
	} while (abs(b - a) <= eps);

	std::cout << "Dyhotomia solution: x = " << halfdyh();
    return halfdyh();
}
