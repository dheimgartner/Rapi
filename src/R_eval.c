#define R_NO_REMAP

#include <R.h>
#include <Rinternals.h>
#include <R_ext/Parse.h>

#define BUG "🦀 "

// static only preserves the C pointer (R's GC does not know about this...)
static SEXP R_env = NULL;

SEXP C_R_eval(SEXP Rexp) {
  if (!Rf_isString(Rexp) || Rf_length(Rexp) != 1) {
    Rf_error(BUG "Rexp must be a length-1 character vector");
  }

  SEXP cmd_parsed, res = R_NilValue;
  ParseStatus status;
  int error_occured;

  cmd_parsed = PROTECT(R_ParseVector(Rexp, -1, &status, R_NilValue));

  if (status != PARSE_OK) {
    UNPROTECT(1);
    Rf_error(BUG "Parse error");
  }

  for (int i = 0; i < Rf_length(cmd_parsed); i++) {
    res = R_tryEval(VECTOR_ELT(cmd_parsed, i), R_env, &error_occured);
    if (error_occured) {
      UNPROTECT(1);
      Rf_error(BUG "Evaluation error");
    }
  }

  UNPROTECT(1);
  return res;
}
