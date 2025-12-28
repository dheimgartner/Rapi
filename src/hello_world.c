#include <R.h>
#include <Rinternals.h>

SEXP C_hello_world(void) {
  Rprintf("hello world\n");
  return R_NilValue;
}
