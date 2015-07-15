def fibonacci_numbers(n):
    "Returns a list of the first n Fibonacci numbers"
    n1 = 0
    n2 = 1
    result = []
    for i in xrange(n):
        result.append(n1)
        n3 = n1 + n2
        n1 = n2
        n2 = n3
    return result

first_fib = fibonacci_numbers(10)
for i in first_fib:
    print i, 
print sum(first_fib)
# How much memory is this taking up?


# Imagine we want to sum the first 1000 fibonacci numbers...
print sum(fibonacci_numbers(1000))
# Do we really need all 1000 numbers in memory at once?
# What if we could "generate" one fib number at a time, add it to our sum,
# then throw it away and generate the next?

