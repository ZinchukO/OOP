#include <iostream>
#include <cmath>
#include "Dyhotomia.h"
#include "Newton_class.h"
using namespace std;

int main()
{
    Dyhotomia dyh;
    dyh.setVolumes(2, 3);
    dyh.setTolerance(0.001);
    dyh.solution();
    cout << "\n\n";
    double x = 0;
    Newton_class newton;
    newton.setInitial(2.25);
    newton.setTolerance(0.001);
    newton.count(x);
    cout << "\n\n";
    return 0;
}