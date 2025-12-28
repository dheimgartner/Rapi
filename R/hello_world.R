#' Hello world example calling C func via .Call
#' @export
hello_world <- function() {
  .Call("C_hello_world", PACKAGE = "Rapi")
}
