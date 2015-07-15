# Before continuing, we should examine Python's memory model
x = 10
# The id() function returns the memory address (or some other unique identifier) of a binding
print "id(x):", id(x)
y = x
print "id(y):", id(y)
# What gets printed?



# So y and x are bound to the same value in memory. Is that what you get for primitive types in C?


# Python binds variables to values in a dictionary called a "namespace"; we call it a
# "referencing environment"
# All values are placed on the heap, and bindings to those values are placed in the namespace.

# All assignment = operators bind a new reference in the namespace
y = 11
print "new id(y):", id(y)
# y previously was bound to the same 10 as x; now it is bound to a different value

# When all bindings to a value are lost, the value may be garbage collected.
y = 100


# This has implications for references to mutable values
a = []
b = a
a.append(1)
print b
# As a Java programmer, what output do you expect?

# Why did we get that output?
