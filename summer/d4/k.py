
s = input()
s = s.split('=')
sec = s[1].split('+')

if sec[0][0] <= '9' and sec[0][0] >= '0':
    a = ""
    for i, c in enumerate(sec[0][::-1]):
        if (i != 0 and i % 3 == 0):
            a += "'"
        a += c
    a = a[::-1]
else:
    a = sec[0]    


if sec[1][0] <= '9' and sec[1][0] >= '0':
    b = ""
    sec[1] = sec[1][::-1]
    for i, c in enumerate(sec[1]):
        if (i != 0 and i % 3 == 0):
           b += "'"
        b += c

    b = b[::-1]
else:
    b = sec[1]    


print(s[0]+'='+a+'+'+b)