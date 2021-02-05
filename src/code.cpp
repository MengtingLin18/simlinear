// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>
#include <Rcpp.h>
using namespace Rcpp;
using namespace arma;
// [[Rcpp::export]]

Rcpp::List simp_lin_cpp(const arma::vec & x, const arma::vec & y) {

  int n = x.size();
  arma::vec intercept(n, arma::fill::ones);

  arma::mat X(n, 2);
  X.col(0) = intercept;
  X.col(1) = x;

  arma::colvec coef = arma::solve(X, y);
  arma::colvec preds = X*coef;
  arma::colvec residuals = y - preds;
  double RSS = arma::as_scalar(arma::trans(residuals)*residuals);
  double sigma2 = RSS/(n-2);
  arma::colvec std_err = arma::sqrt(sigma2*arma::diagvec(arma::inv(arma::trans(X)*X)));

  double m = (double)n;
  double quant = R::qt(0.975, m-2, true, false);

  arma::colvec moe = quant*std_err;
  arma::colvec lb = coef - moe;
  arma::colvec ub = coef + moe;

  arma::mat confint(coef.size(), 2);
  confint.col(0) = lb;
  confint.col(1) = ub;

  return Rcpp::List::create(
    Rcpp::Named("coefficients") = coef,
    Rcpp::Named("standard_error") = std_err,
    Rcpp::Named("conf_interval") = confint,
    Rcpp::Named("residuals") = residuals,
    Rcpp::Named("predicted") = preds);
}
