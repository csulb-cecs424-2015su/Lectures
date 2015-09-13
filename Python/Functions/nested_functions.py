# Python allows functions to be nested in other functions.
def fun1(param1):
    local1 = param1 * 2
    local2 = [1, 2, 3]

    # A nested function.
    def fun2(param2):
        local2.append(param2)
        return param2 % local1

    # When a nested function is executed, its referencing environment
    # is created with references assigned to all values in the scope of the
    # outer function. When we call fun2, it will have bindings that reference
    # the values of local1, local2, and param1. If those are mutable values,
    # changes made in fun2 to their values will also affect fun1's scope.
    
    local3 = fun2(99)
    return local3

print(fun1(13))

# Why would you want to do this?
