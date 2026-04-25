a = None
n = 0

while n < 9 :
    b = int(input())
    n = n + 1
    if a is None:
        a = b
        number = 1
    if b > a :
        a = b
        number = n

print (a)
print (number)
