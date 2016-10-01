context("Detecting BOMs in files and vectors")
test_that("we can do something", {

  expect_equal(
    file_has_bom(system.file("examples", "stops.txt", package="bom")),
    FALSE
  )

  expect_equal(
    file_has_bom(system.file("examples", "stop_times.txt", package="bom")),
    TRUE
  )

  expect_equal(
    raw_has_bom(readBin(system.file("examples", "stop_times.txt", package="bom"), "raw", 4)),
    TRUE
  )

  expect_equal(
    is.na(file_bom_type(system.file("examples", "stops.txt", package="bom"))),
    TRUE
  )

  expect_equal(
    file_bom_type(system.file("examples", "stop_times.txt", package="bom")),
    "UTF-8"
  )

  expect_equal(
    raw_bom_type(readBin(system.file("examples", "stop_times.txt", package="bom"), "raw", 4)),
    "UTF-8"
  )

})
