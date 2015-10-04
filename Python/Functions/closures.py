# Suppose we want a function that creates a function to raise a value
# to a specific exponent.
def power_function(exponent):

    # A nested function.
    def raise_power(base):
        return base ** exponent # ** is raising to a power in Python

    return raise_power # note this


fourth_power = power_function(4)
print(fourth_power) # "<function power_function.<locals>.raise_power>"
# fourth_power is a function that takes one argument, and raises that
# argument to the fourth power.

# I can use it like this:
print(fourth_power(2)) # 16
print(fourth_power(3)) # 81


# Think about how that must have worked... we executed the function "raise_power"
# which was only declared in the scope of power_function.
#
# Since we are no longer in power_function, its parameters are no longer in scope.
# So when raise_power is finally executed... how does "ebase ** exponent" actually
# work?


x = power_function(2)
y = power_function(3)

print(x(3), y(3))
