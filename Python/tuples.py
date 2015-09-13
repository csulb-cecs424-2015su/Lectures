# a tuple is similar to a list, but immutable
person = ("Neal", "Terrell", "CECS")
print(person[0])

# tuples can be "unpacked" into multiple variables
first, last, department = person

# tuple values cannot be modified; a tuple's size is fixed
# what does this imply about their performance vs. lists?

# we have a file of lines of the form "name,shares,price"
portfolio = []
for line in open("portfolio.csv"):
    fields = line.split(",") # fields is a list of strings
    stock = (fields[0], int(fields[1]), float(fields[2]))
    portfolio.append(stock)

print("Your portfolio:")
print("\n".join(["%s: %d shares at $%0.2f" % (s[0], s[1], s[2]) \
                 for s in portfolio]))
print("Total value: $%0.2f" % sum([s[1] * s[2] for s in portfolio]))
# explain what just happened!



#for s in portfolio:
#    print "%s: %d shares at $%0.2f" % (s[0], s[1], s[2])
