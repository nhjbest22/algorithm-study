num = int(input())
count = 0
current = 0
for line in range(num) :
    words = input()
    for word in words :
        if word == "O" :
            current = current + 1
            count = count + current
        if word == "X" :
            current = 0
    print (count)
    count= 0
    current = 0