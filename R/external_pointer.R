
#' @export
make_obj <- function() {
  .Call("C_make_obj", PACKAGE = "Rapi")
}

#' @export
unmake_obj <- function(x_ptr) {
  .Call("C_unmake_obj", x_ptr, PACKAGE = "Rapi")
}

#' @export
get_obj_at <- function(x_ptr) {
  .Call("C_get_obj_at", x_ptr, PACKAGE = "Rapi")
}
