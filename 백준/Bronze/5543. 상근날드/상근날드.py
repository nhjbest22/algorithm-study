n = 0
a = 0
b = 0
b = int (input())
a = b
while n < 2 :
    b = int (input())
    if a > b :
        a = b
        n = n + 1
    else :
        n = n + 1

drink_1 = int (input())
drink_2 = int (input())
if drink_1 > drink_2 :
    drink_1 = drink_2

print ((a+drink_1) - 50)