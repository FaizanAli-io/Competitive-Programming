#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    int n, m, i = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    string sol = "";

    if (m >= n)
    {
        for (; i < n; i++)
            sol += "GB";
        for (; i < m; i++)
            sol += "G";
    }

    else
    {
        for (; i < m; i++)
            sol += "BG";
        for (; i < n; i++)
            sol += "B";
    }

    cout << sol;
}
