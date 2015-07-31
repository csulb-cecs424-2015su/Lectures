x = 10
def f(param1, param2):
    def g():
        return x * param2

    def h():
        return x + param2

    if param1 % 2 == 0:
        return g
    else:
        param2 = param2 + 5
        return h
r1 = f(7, 5)
r2 = f(4, 9)
x = 100
print r1()
print r2()
