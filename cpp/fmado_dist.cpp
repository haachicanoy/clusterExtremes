#include <Rcpp.h>

using namespace Rcpp;

// Function to compute fmado distance
NumericMatrix get_fmado_dist(NumericMatrix x) {
  int Nnb = x.ncol();
  int Tnb = x.nrow();
  NumericMatrix V(Tnb, Nnb);
  
  for (int p = 0; p < Nnb; ++p) {
    NumericVector x_vec = x(_, p);
    
    if (is_true(all(is_na(x_vec)))) {
      V(_, p) = x_vec;
      continue;
    }
    
    Function ecdf("ecdf");
    NumericVector Femp = ecdf(x_vec);
    V(_, p) = Femp;
  }
  
  // Compute manhattan distance manually
  NumericMatrix V_transpose = transpose(V);
  NumericMatrix DD_fmado(Nnb, Nnb);
  
  for (int i = 0; i < Nnb; ++i) {
    for (int j = i; j < Nnb; ++j) {
      double dist_sum = 0.0;
      for (int t = 0; t < Tnb; ++t) {
        dist_sum += std::abs(V(t, i) - V(t, j));
      }
      DD_fmado(i, j) = DD_fmado(j, i) = dist_sum / (2 * Tnb);
    }
  }
  
  return DD_fmado;
}

// [[Rcpp::export]]
NumericMatrix rcpp_get_fmado_dist(NumericMatrix x) {
  return get_fmado_dist(x);
}
