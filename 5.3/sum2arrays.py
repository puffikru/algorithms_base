n, m, x = map(int, input().split())
a = []
b = []
data1 = map(int, input().split())
for i in data1:
    a.append(i)

data2 = map(int, input().split())
for j in data2:
    b.append(j)


def solve(a, b, x):
    r = len(b) - 1
    for l in range(len(a)):
        while r >= 0 and a[l] + b[r] > x:
            r -= 1
        if r >= 0 and a[l] + b[r] == x:
            return str(l + 1) + " " + str(r + 1)
    return str(0) + " " + str(0)


print(solve(a, b, x))