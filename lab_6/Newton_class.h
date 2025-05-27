#ifndef NEWTON_CLASS_H
#define NEWTON_CLASS_H

class Newton_class {
private:
    double x0, eps;

public:
    Newton_class(void);
    ~Newton_class();

    void setInitial(double start);
    void setTolerance(double tolerance);
    int count(double &x);

    double f(double x);
    double f_prime(double x); 
};

#endif
