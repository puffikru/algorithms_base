
n, x = map(int, input().split())
m = []
data = map(int, input().split())
for i in data:
    m.append(i)

def solve(data, X):
    r = 0
    sum = 0
    if len(data) == 1 and X == data[0]:
        return str(1) + " " + str(1)
    for l in range(len(data)):
        while r < len(data) and sum < X:
            sum += data[r]
            r += 1
        if sum == X:
            return str(l + 1) + " " +  str(r)
        sum -= data[l]
    return str(1) + " " + str(0)

print(solve(m, x))
