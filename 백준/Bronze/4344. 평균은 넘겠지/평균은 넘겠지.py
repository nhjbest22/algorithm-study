case = int(input())
for event in range(case) :
    num = 0
    total = 0
    line = input()
    words = line.split()
    for word in words[1:] :
        total = total + int(word)
    avg = total/(len(words)-1)
    for word in words[1:] :
        if int(word) > avg :
            num = num + 1
    pro = (num/(len(words)-1))*100
    round(pro,3)
    print (format(pro, ".3f")+"%")
    
