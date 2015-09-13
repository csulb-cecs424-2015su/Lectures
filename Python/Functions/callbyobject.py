# Python's term for passing arguments to functions is "call by object".
# What does that mean?

# It's easy to overcomplicate, so don't. When an argument is passed to
# a function, the function's namespace binds its parameter name to the
# passed argument in the same way that any other assignment is handled.
# This means the parameter refers to the same value on the heap as the
# argument supplied to the function. If that argument is mutable, then
# any change in the function will affect all references to that value.

def changeImmutable(integer):
    integer += 10000

def changeMutable(lst):
    lst.append(1000)

x = 10
print("Before function:", x)
changeImmutable(x)
print("After function:", x)

y = [1, 2, 3]
print("Before function:", y)
changeMutable(y)
print("After function:", y)

# Python does not have true "pass by reference" like C/C++ does.
# There is no way for me to pass y to a function, and have that
# function assign *MY* "y" to a new value. The function can only
# mutate the actual value y points to, if that value is mutable.
