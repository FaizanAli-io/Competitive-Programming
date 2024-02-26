#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        long int val = INT32_MAX;

        for (int j = 0; j < n; j++)
        {
            long int x;
            cin >> x;
            val &= x;
        }

        cout << val << endl;
    }
}
