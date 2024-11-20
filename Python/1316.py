n = int(input())
non = 0

for i in range (n):
    str = [] 
    prev = ' '
    for c in input():
        if c == prev:
            continue
        if c in str:
            non += 1
            break
        prev = c
        str.append (c)
print (n - non)