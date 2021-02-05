#' Fit a simple linear regression model
#' @param  x vector, the predictor variable in simple linear regression
#' @param  y vector, the response variable in simple linear regression
#' @return a list of regression result
#' @export
simp_lin_R <- function(x, y){
  if(!class(x) %in% c('numeric', 'integer')) stop('x must be a numeric vector.')
  if(!class(y) %in% c('numeric', 'integer')) stop('y must be a numeric vector.')
  if(length(x) != length(y)) stop('x and y must be the same length.')

  return(simp_lin_cpp(x = x, y = y))
}
