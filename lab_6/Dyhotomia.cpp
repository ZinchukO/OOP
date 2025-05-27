#include "Dyhotomia.h"
#include <cmath>
#include <iostream>

Dyhotomia::Dyhotomia(void) {}

Dyhotomia::~Dyhotomia(void) {}

void Dyhotomia::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia::setTolerance(double vol_eps) {
    eps = vol_eps;
}

double Dyhotomia::halfab(void) {
    return (a + b) / 2;
}

double Dyhotomia::solution(void) {
    auto f = [](double x) {
        return 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
    };

    auto log_f = [&](double x, const std::string& label) {
        std::cout << "f(" << label << ") = " << f(x) << "    " << label << " = " << x << "\n";
    };

    double fa = f(a);
    double fb = f(b);
    log_f(a, "a");
    log_f(b, "b");

    if (fa * fb > 0) {
        std::cout << "No roots";
        return 1;
    }

    do {
        double c = halfab();
        double fc = f(c);
        log_f(c, "c");

        if (f(a) * fc < 0) {
            b = c;
        } else {
            a = c;
        }
    } while (abs(b - a) > eps);

    double root = halfab();
    std::cout << "Dyhotomia solution: x = " << root << "\n";
    std::cout << "f(Dyhotomia solution) = " << f(root) << "\n";

    return root;
}
