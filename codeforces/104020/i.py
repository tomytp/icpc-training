import math
n, q = [int(x) for x in input().split()]

def parse(s):
    l = s.split()
    return [(float(l[0]), l[1]), (float(l[3]), l[4])]

unt = dict()
cnt = 0

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

matrix = [[0 for i in range(cnt)] for j in range(cnt)]
g = [[] for i in range(cnt)]

for i in range(cnt):
    matrix[i][i] = 1

for l in lst:
    vai = l[1][0] / l[0][0]
    volta = l[0][0] / l[1][0]
    matrix[unt[l[0][1]]][unt[l[1][1]]] = vai
    matrix[unt[l[1][1]]][unt[l[0][1]]] = volta
    g[unt[l[0][1]]].append((unt[l[1][1]], vai))
    g[unt[l[1][1]]].append((unt[l[0][1]], volta))


def dfs(u, orig, p, prod):
    for v, val in g[u]:
        if (v == p):
            continue
        
        matrix[orig][v] = prod * val
        dfs(v, orig, u, prod * val)

for i in range(cnt):
    dfs(i, i, -1, 1)


ans = []
for i in range(q):
    l = input().split()
    val = float(l[0])
    a = unt[l[1]]
    b = unt[l[3]]
    conv = matrix[a][b]
    if (conv == 0):
        ans.append("impossible")
    else:
        ans.append(matrix[a][b] * val)

print(*ans, sep='\n')