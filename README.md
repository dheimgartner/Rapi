# Rapi

http://adv-r.had.co.nz/C-interface.html

https://cran.r-project.org/doc/manuals/R-exts.html

It is good practice for DLLs to register their symbols (see Registering native routines), restrict visibility (see Controlling visibility) and not allow symbol search (see Registering native routines). It should be possible for a DLL to have only one visible symbol, `R_init_pkgname`, on suitable platforms, which would completely avoid symbol conflicts.

At the heart of every C function are conversions between R data structures and C data structures. Inputs and output will always be R data structures (`SEXP`s) and you will need to convert them to C data structures in order to do any work.

C functions (intended for `.Call` API) must always return a `SEXP`!

C objects (on the heap) are unaffected by R's garbage collector (i.e., only R objects need to be protected)!

I.e., it should be possible to write an R-independent C API and then wrap and expose its core functionality to be callable/usable from R.

You can use external pointers to return a pointer to a C object (on the heap) to R (see `external_pointer.c`)

Use `#define R_NO_REMAP` to force clear namespacing `R_` or `Rf_` prefix.
