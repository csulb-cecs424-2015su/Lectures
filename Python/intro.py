print "$1000 in a bank account with 5% interest"

# as a dynamically typed language, types are not associated with names but
# with values.
principal = 1000   # initial amount
rate = 0.05
numyears = 5
year = 1
while year <= numyears:
    # blocks are based on indentation
    principal = principal * (1 + rate)
    # what type of variable is principal bound to now?
    
    print "%3d %0.2f" % (year, principal)
    year += 1


# dynamic typing means we won't know if any line is valid
# until it is executed.
year += "a" # can't add int + string
