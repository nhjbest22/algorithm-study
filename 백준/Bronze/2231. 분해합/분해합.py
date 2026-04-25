data = input()
def func (n) :
    if n < 0 :
        return func (0)
#    print (n)
    val = str(n)
    sum = int(val)
    length = len(val)

    for i in range (int(length)) :

        sum= sum + int(val[i])

#    print ("sum :",sum )
    if sum == int(data) :
        return n
    if n == int (data) :
        return 0
    else :
        return func (n + 1)

print (func (int(data)-54))