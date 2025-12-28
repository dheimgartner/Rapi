#' R's complete C API
RCAPI <- function() {
  rinternals <- file.path(R.home("include"), "Rinternals.h")
  file.show(rinternals)
}
