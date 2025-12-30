#' @export
R_eval <- function(Rexp) {
  .Call("C_R_eval", Rexp, PACKAGE = "Rapi")
}
