data = input()
words = data.split()
words[0] = int(words[0])
words[1] = int(words[1])
if (words[1]) < 45 :
    if words[0] == 0 :
        words[0] = 23
        words[1] = words[1] + 15
        print (words[0],words[1])
    else :
        print (words[0]-1,words[1]+15)
else :
    print (words[0],words[1]-45)