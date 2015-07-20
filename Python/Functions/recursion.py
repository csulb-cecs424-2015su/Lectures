# A simple recursive implementation of factorial
def factorial(n):
    if n <= 1:
        return 1
    return n * factorial(n-1)

print factorial(5)


# A tail-recursive implementation of factorial
def factorial_tail(n, prod):
    if n <= 1:
        return prod
    return factorial_tail(n-1, prod * n)# Why does this work?
                                        # Why is it better?

# Names can be re-bound to new values at any time.
def factorial(n):
    print "Tail factorial" # To be sure our new version is running
    return factorial_tail(n, 1)

print factorial(5)
