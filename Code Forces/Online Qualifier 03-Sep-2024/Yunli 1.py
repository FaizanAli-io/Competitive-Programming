def longest_consecutive_subarray(arr):
    if not arr:
        return []

    longest_length = 0
    current_start = 0

    for i in range(1, len(arr)):
        if arr[i] == arr[i - 1] + 1:
            continue

        else:
            current_length = i - current_start
            if current_length > longest_length:
                longest_length = current_length
            current_start = i

    current_length = len(arr) - current_start
    if current_length > longest_length:
        longest_length = current_length

    return longest_length


t = int(input())
for i in range(t):

    n, k, q = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    for j in range(q):
        l, r = list(map(int, input().split()))
        len_sub = longest_consecutive_subarray(arr[l - 1 : r])

        print(k - len_sub)
