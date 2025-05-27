#include "Newton_class.h"
#include <cmath>
#include <iostream>

using namespace std;

Newton_class::Newton_class() {}
Newton_class::~Newton_class() {}

void Newton_class::setInitial(double start) {
    x0 = start;
}

void Newton_class::setTolerance(double tolerance) {
    eps = tolerance;
}

int Newton_class::count(double &x) {
    double x1 = x0;
    int iterations = 0;

    auto f = [](double x) {
        return 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
    };

    auto f_prime = [](double x) {
        return 3 * cos(sqrt(x)) / (2 * sqrt(x)) + 0.35;
    };

    do {
        if (f_prime(x1) == 0) {
            cout << "Prime = 0, can't use method" << endl;
            return 1;
        }

        x1 = x1 - f(x1) / f_prime(x1);
        iterations++;
    } while (fabs(f(x1)) > eps);

    x = x1;
    cout << "Newton solution: x = " << x1 << "\n";
    cout << "f(Newton solution) = " << f(x1) << "\n";

    return 0;
}
