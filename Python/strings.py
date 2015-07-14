# strings can be enclosed in single, double, or triple quotes
a = "Hello world"
b = 'CECS 424 is awesome'
c = """Triple-quoted strings
can go more than one line"""

# can index strings with []
d = a[0] # d = 'H'

# the slicing operator [i:j] can extract substrings from index
# i <= k < j
e = a[2:5]  # e == "llo"
f = b[:4]   # f == "CECS"
g = b[5:]   # g == "424 is awesome"

# concatenation with +
h = a + b
# repetition with *
print a * 2

# parse with int()
print "5" + "2" # "52"
print int("5") + int("2") # 7

# values can be converted to strings with str()
print str(100) # "100"
