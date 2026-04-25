dic = {}
for case in range(10) :
    num = input()
    na = int(num)%42
    dic [na] = dic.get(na,0) + 1
print (len(dic))
