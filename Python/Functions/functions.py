def greeting():
    "This is a string for documentation"
    print("Hello, world!")


# "main"
greeting()

def fahrenheit_to_celcius(degrees_f):
    "Converts Fahrenheit degrees to Celcius"
    return float(degrees_f - 32) * 5 / 9

print("88 degrees Fahrenheit is %0.1f degrees Celcius" % \
      fahrenheit_to_celcius(88))

# More practice with list comprehensions
temps_f = [79, 64, 83, 41, 212, 32]
temps_c = [fahrenheit_to_celcius(f) for f in temps_f]
print("\n".join(["%d F == %0.1f C" % (temps_f[i], temps_c[i]) \
                 for i in range(len(temps_f))]))
