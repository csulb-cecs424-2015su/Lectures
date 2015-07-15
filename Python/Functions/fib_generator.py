def fibonacci_numbers(n):
    "Generates the first n fibonacci numbers"
    n1, n2 = 0, 1 # multiple variable declarations
    for i in xrange(n):
        yield n1  # what is this keyword?
        n3 = n1 + n2
        n1 = n2
        n2 = n3

for i in fibonacci_numbers(10):
    print i,
print sum(fibonacci_numbers(10))    

# A generator function returns an iterable sequence that provides one value at
# a time through the yield statement. Each time yield is executed, the 
# function's local state is "saved" for later. The next time a value is
# requested from the generator, the state resumes after the yield and proceeds
# until another yield statement is executed. The iteration ends when the
# generator returns, either from a return statement or by reaching the end
# of its body.

# Generators can be used in any statement expecting an iterable value
fib_sq = [f * f for f in fibonacci_numbers(10)] # squares of fib numbers
is_fib = 24 in fibonacci_numbers(10) # is 24 one of the first 10 fib?

# In effect we have a way of creating a "lazy sequence": a sequence of values
# following some rule/pattern, where values are not instantiated or kept in
# memory until they are needed, and released immediately afterward.
