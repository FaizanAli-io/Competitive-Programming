n = int(input())

final = 0

for _ in range(n):
    final += 1 if "++" in input() else -1

print(final)
