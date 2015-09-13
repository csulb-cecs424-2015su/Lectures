globalvalue = 100

def func():
    return globalvalue * 2

globalvalue = 1
print(func())
# What is the output?


# Does this change with nested functions?
def func2(param1):
    def inner():
        return param1 + globalvalue
    return inner

f = func2(5)
print(f()) # What is the output?

globalvalue = 1000
print(f())
# What is the output now? Is that the only possible way a language
# might handle this?
