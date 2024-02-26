#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char **arr = new char *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[m + 1];
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
        arr[i][m] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}