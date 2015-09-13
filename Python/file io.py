# read from file
f = open("file io.py")
line = f.readline()
while line:
    print(line, end="") # omits the newline
    line = f.readline()
f.close()

# write to file
f = open("output.txt", "w")
principal = 1000
rate = 0.05
year = 1
numyears = 10
while year <= numyears:
    principal = principal * (1 + rate)
    print("%3d %0.2f" % (year, principal), file=f)
    year += 1
f.close()
