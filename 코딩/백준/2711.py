T = int(input())

for i in range(T):
    index = int(input())
    str = input()
    print(str[0:index-1] + str[index:len(str-1)])