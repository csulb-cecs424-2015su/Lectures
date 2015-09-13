# lists are created with square brackets; these are NOT arrays
names = ["Neal", "David", "Mark", "Ada", "Michelle"]
print(names[0], len(names))

# lists are mutable
names[0] = "Jaclyn"
names.append("Barry")
names.insert(4, "Thomas")

# slicing lists
b = names[1:4]
print(b)
names[0:2] = ["Jeff", "Sandee", "Vicky"] # replace elements 0 and 1 with the
                                         # list on the right
print(names)


# other operations
a = [] + [1, 2] + [3, 4, 5]
print(a)

# lists can contain mixed types of values, including other lists
a = [1, "Neal", 3.14, [1, 2, "Hello"]]
print(a[3][2])


# a "real" program
f = open("values.txt")
lines = f.readlines()
f.close()

# a "list comprehension"
ivalues = [int(line) for line in lines]
print("The minimum value is", min(ivalues))
print("The maximum value is", max(ivalues))

# we can shorten the above code to
ivalues = [int(line) for line in open("values.txt")]


# python does not have a C-style for loop; python's for loop
# uses a list of values to iterate a counter through
for i in [0,1,2,3,4,5]:
    print(i)

for i in range(6):
    print(i)
