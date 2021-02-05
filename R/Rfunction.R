#' Fit a simple linear regression model
#' @param  x vector, the predictor variable in simple linear regression
#' @param  y vector, the response variable in simple linear regression
#' @return a list of regression result.
#' coefficient: the estimated regression coefficents, intercept and slope.
#' standard_error: the estimated standard errors for the coefficients,intercept and slope.
#' conf_interval: the 95% confidence intervals for population intercept and slope.
#' residuals: the residuals, that is response minus fitted values.
#' predicted: the predicted value for each observation.
#' @examples
#' slm <- simp_lin_R(x = cars$speed, y = cars$dist)
#' slm$standard_error
#' slm$conf_interval
#' slm$residuals
#' @export
simp_lin_R <- function(x, y){
  if(!class(x) %in% c('numeric', 'integer')) stop('x must be a numeric vector.')
  if(!class(y) %in% c('numeric', 'integer')) stop('y must be a numeric vector.')
  if(length(x) != length(y)) stop('x and y must be the same length.')

  return(simp_lin_cpp(x = x, y = y))
}
