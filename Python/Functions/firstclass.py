# Demonstrate that functions are first-class citizens in Python

def fun1(param1):
    print("I am in fun1 with param1=", param1)

# First class citizens can be passed as a parameter, assigned to a variable,
# and returned from a procedure.

x = fun1
x(1)
# fun1 can be assigned to a variable

def fun2(f):
    print("I am in fun2 and I will now call my parameter function")
    f(2)

fun2(fun1)
# fun1 can be passed as a parameter

def fun3():
    return fun1

print(fun3())
# fun1 can be returned from a procedure

# So functions are first-class citizens in Python! Yay!
