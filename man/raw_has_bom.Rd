% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{raw_has_bom}
\alias{raw_has_bom}
\title{Test if a raw vector has a BOM}
\usage{
raw_has_bom(x)
}
\arguments{
\item{x}{raw vector}
}
\description{
Test if a raw vector has a BOM
}
\examples{
raw_has_bom(readBin(system.file("examples", "stop_times.txt", package="bom"), "raw", 4))
}

