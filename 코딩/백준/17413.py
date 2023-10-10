S = list(input().split())

for i in S:
    if '<' not in i:
        print(i[::-1], end = ' ')
    else:
        left = i.find('<')
        right = i.find('>')
        print(i[0:left:-1], end = '')
        print(i[left:right+1], end = '')
        print(i[:right:-1], end = '')