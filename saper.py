import random


m = int(input())
n = int(input())
p = float(input())
mas = [[0]*(n + 2) for i in range(m + 2)]
ans = [[0]*n for i in range(m)]


for i in range(1, m):
    for j in range(1, n):
        k = random.random()
        if k <= p:
            mas[i][j] = 1

#
for i in range(0, m + 1):
    for j in range(0, n + 1):
        print(mas[i][j], ' ', end='')
    print()
#

for i in range(1, m):
    for j in range(1, n):
        if mas[i][j] == 0:
            ans[i][j] = mas[i - 1][j - 1] + mas[i - 1][j] + mas[i - 1][j + 1] + mas[i][j - 1] + mas[i][j + 1] + mas[i + 1][j - 1] + mas[i+1][j] + mas[i+1][j+1]
        else:
            ans[i][j] = '*'


for i in range(1, m):
    for j in range(1, n):
        print(ans[i][j], ' ', end='')
    print()
