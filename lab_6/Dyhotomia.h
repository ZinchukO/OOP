#pragma once
#include <iostream>
#include <cmath>
#include <math.h>

class Dyhotomia
{
private:
	double a;
	double b;
	double eps;

public:
	Dyhotomia(void);
	~Dyhotomia(void);
	void setVolumes(double vol_a, double vol_b);
	void setTolerance(double vol_eps);
	double halfab(void);
	double func(double a, double b);
	double solution(void);
};