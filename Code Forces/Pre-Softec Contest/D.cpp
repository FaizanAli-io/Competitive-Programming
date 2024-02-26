#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> e(n);
        for (int j = 0; j < n; j++)
            cin >> e[j];

        sort(e.begin(), e.end());

        int groups = 0;
        for (int j = 0; j < n;)
        {
            int x = e[j];
            for (int k = 0; k < x; k++)
            {
            }
        }

        cout << groups << endl;
    }
}