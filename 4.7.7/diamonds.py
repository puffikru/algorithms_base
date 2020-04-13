n, k = map(int, input().split())
v = [0] * n
w = [0] * n
for i in range(n):
    v[i], w[i] = map(int, input().split())

l = 0
r = 10 ** 7
while r - l >= 10 ** -7:
    m = (l + r) / 2

    value = [0] * n
    for i in range(n):
        value[i] = v[i] - w[i] * m
    value.sort(reverse=True)

    s = 0
    for i in range(k):
        s += value[i]

    if s >= 0:
        l = m
    else:
        r = m

print('%.5f' % l)