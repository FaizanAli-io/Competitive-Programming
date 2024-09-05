n, m, k = tuple(map(int, input().split()))

armies = [int(input()) for i in range(m+1)]

fedor = armies.pop()

friends = 0

for army in armies:
    diff = str(bin(army ^ fedor))[2:].count('1')
    if diff <= k:
        friends+=1

print(friends)