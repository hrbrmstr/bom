
`bom` : Tools to Identify and Work with Byte Order Marks

Byte order marks (BOM) appear at the beginning of a file or buffer and provide information about the encoding of the contents. R provides facilities to work with files and connections with BOMs but there are situatons where these facilities are not sufficient. Tools are provided to identify the presence and type of byte order marks in files and R objects as well as remove them.

The following functions are implemented:

-   `file_bom_type`: Get BOM type (file)
-   `file_has_bom`: Test if a file has a BOM
-   `raw_bom_type`: Get BOM type (raw vector)
-   `raw_has_bom`: Test if a raw vector has a BOM

### TODO

-   \[ \] Convert to S3 methods
-   \[ \] BOM removal functions
-   \[ \] Mechanism to return a `connection` sans BOM or identify there is a BOM

### Installation

``` r
devtools::install_git("https://gitlab.com/hrbrmstr/bom.git")
```

``` r
options(width=120)
```

### Usage

``` r
library(bom)

# current verison
packageVersion("bom")
```

    ## [1] '0.1.0'

``` r
file_has_bom(system.file("examples", "stops.txt", package="bom"))
```

    ## [1] FALSE

``` r
file_has_bom(system.file("examples", "stop_times.txt", package="bom"))
```

    ## [1] TRUE

``` r
raw_has_bom(readBin(system.file("examples", "stop_times.txt", package="bom"), "raw", 4))
```

    ## [1] TRUE

``` r
file_bom_type(system.file("examples", "stops.txt", package="bom"))
```

    ## [1] NA

``` r
file_bom_type(system.file("examples", "stop_times.txt", package="bom"))
```

    ## [1] "UTF-8"

``` r
raw_bom_type(readBin(system.file("examples", "stop_times.txt", package="bom"), "raw", 4))
```

    ## [1] "UTF-8"

### Test Results

``` r
library(bom)
library(testthat)

date()
```

    ## [1] "Sat Oct  1 08:52:10 2016"

``` r
test_dir("tests/")
```

    ## testthat results ========================================================================================================
    ## OK: 6 SKIPPED: 0 FAILED: 0
    ## 
    ## DONE ===================================================================================================================
