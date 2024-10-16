/**
 * This is the smole test that comes with the Armadillo lib.
 * The purpose is to ensure that LAPACK is working well together with the Armadillo.
 * Make sure you can runs this test without any problems!
 */

#define ARMA_USE_LAPACK // This definition must be before the include to the armadillo
#define ARMA_DONT_PRINT_FAST_MATH_WARNING

#include <iostream>
#include <armadillo>

using namespace arma;

#if defined(BUILD_MONOLITHIC)
#define main   kalman_main0_example_main
#endif

extern "C"
int main(void)
{
    std::cout << "*** smoke test start" << std::endl;

    uword N = 5;

    mat A = reshape(regspace(1, N * N), N, N);

    A.diag() += randu<vec>(N);

    mat B;

    bool status = expmat(B, A);

    A.print("A:");
    B.print("B:");

    std::cout << ((status) ? "*** smoke test okay" : "*** smoke test failed") << std::endl;

    return (status) ? 0 : -1;
}
