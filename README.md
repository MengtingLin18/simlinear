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
# fit the simple linear model
slm <- simp_lin_R(x = cars$speed, y = cars$dist)
#results
slm
```
