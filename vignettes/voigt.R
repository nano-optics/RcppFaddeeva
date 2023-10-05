## ----plot---------------------------------------------------------------------
palette(c(c("#000000", "#E41A1C", "#377EB8", "#4DAF4A", "#984EA3", "#FF7F00"), palette()))
library(RcppFaddeeva)
x <- seq(-300, 800)
x0 <- 200
l <- Lorentz(x, x0, 30)
g <- Gauss(x, x0, 100)

## brute-force convolution
# (discrete convolve() would perform better but indexing is tricky)
lg <- function(x) {
  integrate(function(t) Lorentz(t, 0, 30) *  Gauss(x-t, x0, 100),
            -Inf, Inf, rel.tol = 1e-6)$value
}
c <- sapply(x, lg)

v <- Voigt(x, x0, 100, 30)
matplot(x, cbind(v, l, g, c), t="l", lty=c(1,1,1,2), xlab="x", ylab="", lwd = 2)
legend("topleft", legend = c("Voigt", "Lorentz", "Gauss", "Convolution"), bty="n",
      lty=c(1,1,1,2), col=1:4, lwd=2)

## ----integrals----------------------------------------------------------------
integrate(Lorentz, -Inf, Inf, x0=200, gamma=100)
integrate(Gauss, -Inf, Inf, x0=200, sigma=50)
integrate(Voigt, -Inf, Inf, x0=200, sigma=50, gamma=100)

## ----complex------------------------------------------------------------------
x <- seq(-1000, 1000)
x0 <- 200
v <- Voigt(x, x0, 100, 30, real = FALSE)
matplot(x, cbind(Re(v), Im(v)), t="l", lty=c(1,2), xlab="", ylab="", col=1, lwd = 2)
legend("topleft", legend = c("Imaginary part", "Real part"), bty="n",
      lty=c(1,2), col=1, lwd = 2)

