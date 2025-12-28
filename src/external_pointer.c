#define R_NO_REMAP  // force clear namespace R_ Rf_

#include <R.h>
#include <Rinternals.h>
#include <stdlib.h>

SEXP C_make_obj(void) {
  int *xp = malloc(sizeof(int));
  if (!xp)
    Rf_error("malloc failed");

  *xp = 41;

  SEXP x_ptr = PROTECT(R_MakeExternalPtr(xp, R_NilValue, R_NilValue));
  UNPROTECT(1);

  return x_ptr;
}

SEXP C_unmake_obj(SEXP x_ptr) {
  int *xp = (int *) R_ExternalPtrAddr(x_ptr);
  if (xp) {
    free(xp);
    R_ClearExternalPtr(x_ptr);
  }
  return R_NilValue;
}

SEXP C_get_obj_at(SEXP x_ptr) {
  int *xp = (int *) R_ExternalPtrAddr(x_ptr);
  if (!xp)
    Rf_error("Pointer is NULL or freed");

  return Rf_ScalarInteger(*xp);
}
