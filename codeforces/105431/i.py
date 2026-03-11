s = int(input(), base=2)
d = int(input(), base=2)
m = int(input(), base=2)

counter = 0
mx = 2*m
inf = False
while True:
    if (m == 0): break
    counter += 1
    m >>= 1
    if (counter %d == 0):
        m += s
        if m >= mx:
            inf = True
            break
        mx = m

if inf:
    print("Infinite money!")
else:
    print(bin(counter)[2:])

