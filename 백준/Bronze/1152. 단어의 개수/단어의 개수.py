data_1 = input()
data = data_1.strip()
word = 1
a = data.find(" ")
if a == -1 :
    data = data + " "
    if int(data.find(" ")) != 0 :
        word = 1
    else :
        word = 0
while a!=int(-1) :
    word = word + 1
    a = data.find(" ", a+1)
    if a == -1 :
        break
print (word)