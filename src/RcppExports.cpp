// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// file_has_bom
bool file_has_bom(std::string path);
RcppExport SEXP bom_file_has_bom(SEXP pathSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type path(pathSEXP);
    rcpp_result_gen = Rcpp::wrap(file_has_bom(path));
    return rcpp_result_gen;
END_RCPP
}
// file_bom_type
CharacterVector file_bom_type(std::string path);
RcppExport SEXP bom_file_bom_type(SEXP pathSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type path(pathSEXP);
    rcpp_result_gen = Rcpp::wrap(file_bom_type(path));
    return rcpp_result_gen;
END_RCPP
}
// raw_has_bom
bool raw_has_bom(SEXP x);
RcppExport SEXP bom_raw_has_bom(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(raw_has_bom(x));
    return rcpp_result_gen;
END_RCPP
}
// raw_bom_type
CharacterVector raw_bom_type(SEXP x);
RcppExport SEXP bom_raw_bom_type(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(raw_bom_type(x));
    return rcpp_result_gen;
END_RCPP
}
