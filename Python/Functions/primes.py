from math import *

def is_prime(n):
    for i in xrange(2, 1 + int(sqrt(n))):
        if n % i == 0:
            return False
    return True

def get_primes(n):
    i = n
    while True:
        if is_prime(i):
            yield i
        i += 1

def sum_primes():
    s = 0
    for n in get_primes(2):
        if n > 2000000:
            break
        s += n
    return s

print sum_primes()
