"""
5
2 7 3 4 9
3
1 25 11
"""

n = int(input())

piles = list(map(int, input().split()))

m = int(input())

juicy = list(map(int, input().split()))

cum = [piles[0]]

for i in range(1, n):
    cum.append(cum[-1] + piles[i])


def binary_search(x, l):
    lb, ub = 0, len(l)
    while lb < ub:
        if lb + 1 == ub and ub < len(l) and l[lb] < x < l[ub]:
            return ub
        mid = (lb + ub) // 2
        if l[mid] < x:
            lb = mid
        elif l[mid] > x:
            ub = mid
        else:
            break
    return mid


for juice in juicy:
    print(binary_search(juice, cum) + 1)
