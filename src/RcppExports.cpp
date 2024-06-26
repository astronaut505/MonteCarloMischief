// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// monte_carlo_barrier_option
double monte_carlo_barrier_option(int n_sim, double S0, double K, double r, double sigma, double T, double barrier, bool is_call, bool is_down_and_out);
RcppExport SEXP _BarrierOptionPricing_monte_carlo_barrier_option(SEXP n_simSEXP, SEXP S0SEXP, SEXP KSEXP, SEXP rSEXP, SEXP sigmaSEXP, SEXP TSEXP, SEXP barrierSEXP, SEXP is_callSEXP, SEXP is_down_and_outSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n_sim(n_simSEXP);
    Rcpp::traits::input_parameter< double >::type S0(S0SEXP);
    Rcpp::traits::input_parameter< double >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< double >::type T(TSEXP);
    Rcpp::traits::input_parameter< double >::type barrier(barrierSEXP);
    Rcpp::traits::input_parameter< bool >::type is_call(is_callSEXP);
    Rcpp::traits::input_parameter< bool >::type is_down_and_out(is_down_and_outSEXP);
    rcpp_result_gen = Rcpp::wrap(monte_carlo_barrier_option(n_sim, S0, K, r, sigma, T, barrier, is_call, is_down_and_out));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_BarrierOptionPricing_monte_carlo_barrier_option", (DL_FUNC) &_BarrierOptionPricing_monte_carlo_barrier_option, 9},
    {NULL, NULL, 0}
};

RcppExport void R_init_BarrierOptionPricing(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
