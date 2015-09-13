# What happens when a nested function is returned?
def fun1(param1):
    local1 = param1 * 2

    # A nested function.
    def fun2(param2):
        return param2 % local1

    return fun2 # note the new return value

f = fun1(13)
print(f) # "<function fun2>"

# Before we execute f, think about the variables that it refers to.
# Since we are no longer in fun1, what value could "param1" possibly have?
# What about "local1"? fun2 uses local1, but local1 is no longer in memory...
# or is it?

# So what do we think will happen when I do this?
print(f(100))
