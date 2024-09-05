n = int(input())
l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))


last_solution = {0: 0, 1: l1[-1], 2: l2[-1]}

for i in range(n - 2, -1, -1):
    new_solution = {
        0: max(last_solution[0], last_solution[1], last_solution[2]),
        1: l1[i] + max(last_solution[0], last_solution[2]),
        2: l2[i] + max(last_solution[0], last_solution[1]),
    }

    last_solution = new_solution

print(max(last_solution.values()))
