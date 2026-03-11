import math
n, q = [int(x) for x in input().split()]

def parse(s):
    l = s.split()
    return [(float(l[0]), l[1]), (float(l[3]), l[4])]

unt = dict()
cnt = 0

INF = float("inf")

lst = []

for i in range(n):
    s = input()
    l = parse(s)
    lst.append(l)

    if (unt.get(l[0][1]) == None):
        unt[l[0][1]] = cnt
        cnt += 1
    if (unt.get(l[1][1]) == None):
        unt[l[1][1]] = cnt
        cnt += 1

matrix = [[INF for i in range(cnt)] for j in range(cnt)]

for l in lst:
    vai = math.log(l[1][0] / l[0][0])
    volta = math.log(l[0][0] / l[1][0])
    matrix[unt[l[0][1]]][unt[l[1][1]]] = vai
    matrix[unt[l[1][1]]][unt[l[0][1]]] = volta

for i in range(cnt):
    matrix[i][i] = 1

for k in range(cnt):
    for i in range(cnt):
        for(j) in range(cnt):
            matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])

ans = []
for i in range(q):
    l = input().split()
    val = float(l[0])
    a = unt[l[1]]
    b = unt[l[3]]
    conv = matrix[a][b]
    if (conv == INF):
        ans.append("impossible")
    else:
        ans.append(math.exp(matrix[a][b]) * val)


print(*ans, sep='\n')