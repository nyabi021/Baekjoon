def d(n):
    now = n
    while True:
        now += n % 10
        n //= 10
        if n == 0:
            return now
a = []
for i in range (1, 10001):
    a.append (d(i))
for j in range (1, 10001):
    if j not in a:
        print (j)
