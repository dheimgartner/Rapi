#' @rawNamespace useDynLib(Rapi, .registration = TRUE)
NULL

#' Memory model
#' @name memory_model
#' @examples
#' \dontrun{
#' High memory addresses
#' +----------------+
#' |  Heap          | <- dynamic allocation, persists until freed (malloc() and free())
#' +----------------+
#' |                |
#' |  (unused)      |
#' |                |
#' +----------------+
#' |  Stack         | <- grows downward, auto allocation (e.g., callstack)
#' +----------------+
#' Low memory addresses
#'   }
NULL
