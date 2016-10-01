
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

There are some basic examples in the [Usage](#Usage) section, but this may be a better illustration. Say you have a CSV file:

``` r
fil <- system.file("examples", "stop_times.txt", package="bom")
```

And, say you want to read it in with a more modern CSV reader:

``` r
library(readr)

df <- read_csv(fil)
```

    ## Parsed with column specification:
    ## cols(
    ##   `﻿trip_id` = col_integer(),
    ##   arrival_time = col_time(format = ""),
    ##   departure_time = col_time(format = ""),
    ##   stop_id = col_integer(),
    ##   stop_sequence = col_integer(),
    ##   pickup_type = col_integer(),
    ##   drop_off_type = col_integer()
    ## )

Let's look at that file:

``` r
print(df, n=1)
```

    ## # A tibble: 64,827 × 7
    ##   `﻿trip_id` arrival_time departure_time stop_id stop_sequence pickup_type drop_off_type
    ##       <int>       <time>         <time>   <int>         <int>       <int>         <int>
    ## 1     50000   29700 secs     29700 secs  120001            41           1             0
    ## # ... with 6.483e+04 more rows

Hrm…why are those backticks around `trip_id`? Isn't it just a regular string?

``` r
print(colnames(df)[1])
```

    ## [1] "﻿trip_id"

It sure *looks* that way, but looks can be deceiving:

``` r
print(charToRaw(colnames(df)[1]))
```

    ##  [1] ef bb bf 74 72 69 70 5f 69 64

Those strange characters at the beginning are a byte order mark (BOM). We can test for it being there and work around it:

``` r
library(bom)

if (file_has_bom(fil)) {
  n <- switch(file_bom_type(fil), `UTF-8`=3, 2)
  df <- read_csv(readBin(fil, "raw", file.size(fil))[-(1:n)])
}
```

    ## Parsed with column specification:
    ## cols(
    ##   trip_id = col_integer(),
    ##   arrival_time = col_time(format = ""),
    ##   departure_time = col_time(format = ""),
    ##   stop_id = col_integer(),
    ##   stop_sequence = col_integer(),
    ##   pickup_type = col_integer(),
    ##   drop_off_type = col_integer()
    ## )

``` r
print(df, n=1)
```

    ## # A tibble: 64,827 × 7
    ##   trip_id arrival_time departure_time stop_id stop_sequence pickup_type drop_off_type
    ##     <int>       <time>         <time>   <int>         <int>       <int>         <int>
    ## 1   50000   29700 secs     29700 secs  120001            41           1             0
    ## # ... with 6.483e+04 more rows

``` r
charToRaw(colnames(df)[1])
```

    ## [1] 74 72 69 70 5f 69 64

Note that the built-in `read.csv()` can be used with `encoding="UTF-8-BOM"` and you can even use that encoding on non-binary connections, but you end up having to type convert and tibble convert that object so you're basically rewriting (badly) `readr::read_csv()`.

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

    ## [1] "Sat Oct  1 09:26:55 2016"

``` r
test_dir("tests/")
```

    ## testthat results ========================================================================================================
    ## OK: 6 SKIPPED: 0 FAILED: 0
    ## 
    ## DONE ===================================================================================================================
