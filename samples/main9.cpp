/**
 * @file main9.cpp
 * @author Auralius Manurung
 * @date 27 Jan 2017
 * 
 * @brief This is to test the class FX to compute Jacobian and Hessian of function(s).
 *
 */

#include "fx.h"


static
colvec foo(colvec &x, colvec &a)
{
    colvec ret(1);
    double y = a.at(0)*x.at(0)*x.at(1)*x.at(2);
    ret << y;
    return ret;
}

/////////////////////////////////////////////////////////////////////////////

#if defined(BUILD_MONOLITHIC)
#define main   kalman_main9_example_main
#endif

extern "C"
int main(int argc, const char** argv)
{
    FX f(&foo);
    colvec x(1);
    colvec a(1);
    x << 1.0 << 2.0 << 3.0;
    a << 2.0;

    colvec y = f.SolveAt(x, a);
    mat jac = f.JacobianAt(x, a);
    mat hess = f.HessianAt(x, a, 0);

    y.print("y");
    jac.print("jac");
    hess.print("hess");
    return 0;
}
