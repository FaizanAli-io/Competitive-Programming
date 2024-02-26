#include <bits/stdc++.h>
using namespace std;

vector<int> absolutePermutation(int n, int k)
{
    vector<int> count(n + 1, 0);

    vector<int> sol(n);

    for (int i = 1; i <= n; i++)
    {
        int a = abs(i + k);
        int b = abs(i - k);

        if ((a > 0 && a <= n && count[a] == 0) && (b > 0 && b <= n && count[b] == 0))
        {
            int c = a < b ? a : b;
            count[c]++;
            sol[i - 1] = c;
            cout << c << " (" << i << ") ";
        }
        else if (a > 0 && a <= n && count[a] == 0)
        {
            count[a]++;
            sol[i - 1] = a;
            cout << a << " (" << i << ") ";
        }
        else if (b > 0 && b <= n && count[b] == 0)
        {
            count[b]++;
            sol[i - 1] = b;
            cout << b << " (" << i << ") ";
        }
        else
        {
            return {-1};
        }
    }

    return sol;
}

int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> sol = absolutePermutation(a, b);

    cout << endl
         << endl;

    for (int a : sol)
        cout << a << ' ';
    cout << endl;
}