# simlinear
This package is to conduct a simple linear regression which wraps cpp function. 

# Install package

```{r}
# install.packages('devtools')
devtools::install_github('MengtingLin18/simlinear')
```

# Example 

```{r}
library(simlinear)
x <- 1:7
y <- 7:1 + rnorm(7)
# fit the simple linear model
slm <- simp_lin_R(x = x, y = y)
# explore results
slm
```
