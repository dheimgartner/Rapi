#' @export
embed_python <- function(argc, argv) {
  .Call("C_embed_python", argc, argv, PACKAGE = "Rapi")
}
