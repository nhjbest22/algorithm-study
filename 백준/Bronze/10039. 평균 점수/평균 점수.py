n = 0
b = 0
while n < 5 :
    a = int (input())
    if a >=40 :
        b = b + a
        n = n + 1
    if a < 40 :
        a = 40
        b = b + 40
        n = n + 1

print (int(b/5))