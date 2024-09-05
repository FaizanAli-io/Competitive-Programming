# Not Accepted

n, s = list(map(int, input().split()))
a = list(sorted(map(int, input().split())))

m = n // 2

ops = 0

if a[m] < s:
    for i in range(m, n):
        if a[i] == s:
            break
        ops += s - a[i]
else:
    for i in range(m, -1, -1):
        if a[i] == s:
            break
        ops += a[i] - s

print(ops)
