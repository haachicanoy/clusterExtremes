# CHANGELOG

This changelog summarizes the modifications made in this fork of **clusterExtremes** relative to the original upstream repository.

## Changes

- Edits on `clusterExtremes/R/get_dist.R` script:  
  **Source file location**: The original uses a local file path (`"/Users/saundersk1/Documents/Git/clusterExtremes/helper/utils_dist.R"`), while the edited version uses a GitHub raw URL (`"https://raw.githubusercontent.com/haachicanoy/clusterExtremes/master/helper/utils_dist.R"`)

- The original code uses SDMTools package which is deprecated. This package contained a function written in C called `pip` implemented in the `clusterExtremes/src/pointinpolygon.c` script used to extracting information about point in polygon. Therefore created in isolation for the purposes of the calculations. Created in the folder `src`. This function is called into the `clusterExtremes/R/pnt.in.poly.R` script.

- Creation of the C++ function `get_fmado_dist` implemented in the script `clusterExtremes/cpp/fmado_dist.cpp` compiled using `Rcpp` package. It replaces the R function with the same name stored in `clusterExtremes/R/get_dist.R` script. It speeds the processing time in particular when all pixels in agricultural production areas are compared.

- `clusterExtremes/R/utils_grid.R` script removes SDMTools dependency.

- `clusterExtremes/R/utils_reduce_grid.R` script removed SDMTools dependency.
