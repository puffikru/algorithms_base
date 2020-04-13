
n, x = map(int, input().split())
m = []
data = map(int, input().split())
for i in data:
    m.append(i)

def solve(data, X):
    r = 1
    sum = 0
    for l in range(1, len(data)):
        while r < len(data) and sum < X:
            sum += data[r - 1]
            r += 1
        if sum == X:
            return (l, r - 1)
        sum -= data[l - 1]
    return (1, 0)

a, b = solve(m, x)
print(a, b)




