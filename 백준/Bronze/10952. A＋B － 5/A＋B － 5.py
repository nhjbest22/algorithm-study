while True :
    line = input()
    if line == "0 0" :
        break
    words = line.split()
    a = int(words[0])
    b = int(words[1])
    print (a+b)