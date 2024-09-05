import math

import numpy as np

t = int(input())


def get_roots(n, k):
    a = 2
    b = (4 * k) - 2
    c = n * (1 - (2 * k) - n)

    return np.roots([a, b, c])


def sum_of_ap(a, n):
    S_n = (n / 2) * (2 * a + (n - 1))
    return S_n


for i in range(t):
    n, k = list(map(int, input().split()))
    root = get_roots(n, k)[1]

    i = math.floor(root)
    j = math.ceil(root)

    s1 = sum_of_ap(k, n)

    s2 = sum_of_ap(k, i)
    s3 = s1 - s2

    s4 = sum_of_ap(k, j)
    s5 = s1 - s4

    s6 = abs(s3 - s2)
    s7 = abs(s5 - s4)

    ans = int(min(s6, s7))

    print(ans)
