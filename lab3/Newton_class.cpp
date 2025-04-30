#include "Newton_class.h"
#include <cmath>
#include <iostream>

Newton_class::Newton_class() {}
Newton_class::~Newton_class() {}

void Newton_class::setInitial(double start) {
    x0 = start;
}

void Newton_class::setTolerance(double tolerance) {
    eps = tolerance;
}

double Newton_class::f(double x) {
    return 3*sin(sqrt(x)) + 0.35*x - 3.8;
}

double Newton_class::f_prime(double x) {
    return 3*cos(sqrt(x)) / (2*sqrt(x)) + 0.35; 
}

int Newton_class::count(double &x) {
    double x1 = x0;
    int iterations = 0;

    do {
        if (f_prime(x1) == 0) {
            std::cout << "Prime = 0, cant ue method" << std::endl;
            return 1;
        }

        x1 = x1 - f(x1) / f_prime(x1);
        iterations++;
    } while (std::fabs(f(x1)) > eps);

    x = x1;
    std::cout << "Newton solution: x = " << x1 << "\n";
    return 0;
}
