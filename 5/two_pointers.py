def solve(a, x):
    r = 0
    sum = 0
    for l in range(len(a)):
        while r < len(a) and sum < x:
            sum += a[r]
            r += 1
        if sum == x:
            return (l, r - 1)
        sum -= a[l]
    return (0, -1)
    