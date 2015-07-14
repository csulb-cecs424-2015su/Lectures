# conditional tests
a = 10
b = 20

if a < b:
    print True
elif b < a: # elif, not "else if"
    print False
else:
    pass # no action

# use "and" "or" "not" for compond conditions
rating = "R"
age = 14
if rating == "R" and not (age >= 18):
    print "Can't see the movie, sorry!"

# the "in" operator can see if a value is "in" something else
has_spam = "spam" in rating # has_spam is False
