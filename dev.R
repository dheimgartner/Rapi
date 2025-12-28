devtools::load_all()

# install.packages("inline")
# install.packages("pryr")

RCAPI()

library(pryr)
sexp_type(c("a", "b"))



devtools::load_all()
hello_world()



## external_pointer
## Write a C function that creates a C object (integer vector not R SEXP) and returns the memory address to it
## Call it and call gc() a couple of times...
## Write a function that returns the object at the address (casting to an SEXP). Call it and check the results.
devtools::load_all()
x_ptr <- make_obj()
x_ptr
x <- get_obj_at(x_ptr)
x
gc()
x
x_ptr
x2 <- get_obj_at(x_ptr)
x2
unmake_obj(x_ptr)
x3 <- get_obj_at(x_ptr)
