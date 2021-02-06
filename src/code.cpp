// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>
#include <Rcpp.h>
using namespace Rcpp;
using namespace arma;
// [[Rcpp::export]]

Rcpp::List simp_lin_cpp(const arma::vec & x, const arma::vec & y) {

  int n = x.n_rows;
  arma::mat X(n, 2);
  X.col(0) = arma::vec(n, arma::fill::ones);
  X.col(1) = x;
  arma::colvec coef = arma::solve(X, y);
  arma::colvec preds = X*coef;
  arma::colvec residuals = y - preds;
  double sigma2 = arma::as_scalar(arma::trans(residuals)*residuals/(n-2));
  arma::colvec std_err = arma::sqrt(sigma2*arma::diagvec(arma::inv(arma::trans(X)*X)));
  arma::colvec moe = R::qt(0.975, n-2, true, false)*std_err;
  arma::colvec lb = coef - moe;
  arma::colvec ub = coef + moe;
  arma::mat confint(coef.size(), 2);
  confint.col(0) = lb;
  confint.col(1) = ub;

  return Rcpp::List::create(
    Named("coefficients") = coef,
    Named("standard_error") = std_err,
    Named("conf_interval") = confint,
    Named("residuals") = residuals,
    Named("predicted") = preds);
}
