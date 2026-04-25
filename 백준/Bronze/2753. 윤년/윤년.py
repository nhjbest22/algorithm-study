s = input()
d = int (s)
if d%4 == 0 :
    if d%100 == 0 :
        if d%400 == 0 :
            print ("1")
        else :
            print ("0")
    else :
        print ("1")
else :
    print ("0")
