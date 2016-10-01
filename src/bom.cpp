#include <Rcpp.h>
using namespace Rcpp;

#include <Rdefines.h>
#include "R_ext/Memory.h"

#include <iostream>
#include <fstream>

std::string buf_bom(char *b) {

  if (!memcmp(b, "\xef\xbb\xbf", 3)) {
    return("UTF-8");
  } else if (!memcmp(b, "\xff\xfe", 2)) {
    return("UTF-16");
  } else if (!memcmp(b, "\xfe\xff", 2)) {
    return("UTF-16BE");
  } else {
    return("");
  }

}

//' Test if a file has a BOM
//' @param path path to a file
//' @export
//' @examples
//' file_has_bom(system.file("examples", "stops.txt", package="bom"))
//' file_has_bom(system.file("examples", "stop_times.txt", package="bom"))
// [[Rcpp::export]]
bool file_has_bom(std::string path) {

  path = R_ExpandFileName(path.c_str());

  std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);

  if (file.good()) {

    char buffer[3];
    file.read(buffer, 3);
    int sz = file.gcount();
    file.close();

    if (sz < 2) return(false);

    return(buf_bom(buffer) != "");

  } else {
    Rcpp::stop("File not found.");
  }

}

//' Get BOM type (file)
//'
//' @param path path to a file
//' @export
//' @examples
//' file_bom_type(system.file("examples", "stop_times.txt", package="bom"))
// [[Rcpp::export]]
CharacterVector file_bom_type(std::string path) {

  path = R_ExpandFileName(path.c_str());

  std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);

  if (file.good()) {

    char buffer[3];
    file.read(buffer, 3);
    int sz = file.gcount();
    file.close();

    if (sz < 2) return(NA_STRING);

    std::string res = buf_bom(buffer);
    return(res == "" ? NA_STRING : wrap(res));

  } else {
    Rcpp::stop("File not found.");
  }

}

//' Test if a raw vector has a BOM
//' @param x raw vector
//' @export
//' @examples
//' raw_has_bom(readBin(system.file("examples", "stop_times.txt", package="bom"), "raw", 4))
// [[Rcpp::export]]
bool raw_has_bom(SEXP x) {

  char *buffer = (char *)RAW(x);
  int sz = GET_LENGTH(x);
  if (sz < 2) return(false);

  return(buf_bom(buffer) != "");

}

//' Get BOM type (raw vector)
//' @param x raw vector
//' @export
//' @examples
//' raw_bom_type(readBin(system.file("examples", "stop_times.txt", package="bom"), "raw", 4))
// [[Rcpp::export]]
CharacterVector raw_bom_type(SEXP x) {

  char *buffer = (char *)RAW(x);
  int sz = GET_LENGTH(x);

  if (sz < 2) return(NA_STRING);

  std::string res = buf_bom(buffer);
  return(res == "" ? NA_STRING : wrap(res));

}
