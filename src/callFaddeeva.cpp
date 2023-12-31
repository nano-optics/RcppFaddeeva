#include <Rcpp.h>

using namespace Rcpp;

#include "Faddeeva.h"

// [[Rcpp::interfaces(r, cpp)]]

//' @title Faddeeva family of error functions of the complex variable
//' @description the Faddeeva function
//' @param z complex vector
//' @param relerr double, requested error
//' @return complex vector
//' @describeIn wrap compute \eqn{w(z) = \exp(-z^2) \, \mathrm{erfc}(-iz)}{w(z) = exp(-z^2) erfc(-iz)}
//' @family wrapper
//' @examples
//' Faddeeva_w(1:10 + 1i)
//' @export
// [[Rcpp::export]]
std::vector< std::complex<double> > Faddeeva_w(const std::vector< std::complex<double> >& z, double relerr=0) {
  int N = z.size();
  std::vector< std::complex<double> > result(N);
  for(int i=0; i<N; i++) {
    result[i] = Faddeeva::w(z[i], relerr);
  }
  return result;
}

//' the scaled complementary error function
//' @describeIn wrap compute \eqn{\mathrm{erfcx}(z) = \exp(z^2) \, \mathrm{erfc}(z)}{erfcx(z) = exp(z^2) erfc(z)}
//' @family wrapper
//' @examples
//' erfcx(1:10 + 1i)
//' @export
// [[Rcpp::export]]
std::vector< std::complex<double> > erfcx(const std::vector< std::complex<double> >& z, double relerr=0) {
  int N = z.size();
  std::vector< std::complex<double> > result(N);
  for(int i=0; i<N; i++) {
    result[i] = Faddeeva::erfcx(z[i], relerr);
  }
  return result;
}

//'  the error function of complex arguments
//' @describeIn wrap compute \eqn{\mathrm{erf}(z)}{erf(z)}
//' @family wrapper
//' @examples
//' erf(1:10 + 1i)
//' @export
// [[Rcpp::export]]
std::vector< std::complex<double> > erf(const std::vector< std::complex<double> >& z, double relerr=0) {
  int N = z.size();
  std::vector< std::complex<double> > result(N);
  for(int i=0; i<N; i++) {
    result[i] = Faddeeva::erf(z[i], relerr);
  }
  return result;
}

//' the imaginary error function
//' @describeIn wrap compute \eqn{\mathrm{erfi}(z) = -i \, \mathrm{erf}(iz)}{erfi(z) = -i erf(iz)}
//' @family wrapper
//' @examples
//' erfi(1:10 + 1i)
//' @export
// [[Rcpp::export]]
std::vector< std::complex<double> > erfi(const std::vector< std::complex<double> >& z, double relerr=0) {
  int N = z.size();
  std::vector< std::complex<double> > result(N);
  for(int i=0; i<N; i++) {
    result[i] = Faddeeva::erfi(z[i], relerr);
  }
  return result;
}

//' the complementary error function
//' @describeIn wrap compute \eqn{\mathrm{erfc}(z) = 1 - \mathrm{erf}(z)}{erfc(z) = 1 - erf(z)}
//' @family wrapper
//' @examples
//' erfc(1:10 + 1i)
//' @export
// [[Rcpp::export]]
std::vector< std::complex<double> > erfc(const std::vector< std::complex<double> >& z, double relerr=0) {
  int N = z.size();
  std::vector< std::complex<double> > result(N);
  for(int i=0; i<N; i++) {
    result[i] = Faddeeva::erfc(z[i], relerr);
  }
  return result;
}

//' the Dawson function
//' @describeIn wrap compute \eqn{\mathrm{Dawson}(z) = \sqrt{\pi}/2 \exp(-z^2) \, \mathrm{erfi}(z)}{Dawson(z) = sqrt(pi)/2 * exp(-z^2) * erfi(z)}
//' @family wrapper
//' @examples
//' Dawson(1:10 + 1i)
//' @export
// [[Rcpp::export]]
std::vector< std::complex<double> > Dawson(const std::vector< std::complex<double> >& z, double relerr=0) {
  int N = z.size();
  std::vector< std::complex<double> > result(N);
  for(int i=0; i<N; i++) {
    result[i] = Faddeeva::Dawson(z[i], relerr);
  }
  return result;
}



