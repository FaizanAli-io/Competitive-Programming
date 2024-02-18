#include <iostream>
using namespace std;

bool getNextSafe(int &x, int &y, int n, int m, char **grid)
{
    int i = x;
    int j = y;

    for (; i < n; i++)
    {
        for (; j < m; j++)
            if (grid[i][j] == '.')
                break;

        if (j < m)
            break;

        j = 0;
    }

    if (i < n)
    {
        x = i;
        y = j;
        return true;
    }

    return false;
}

bool solve(int &x, int &y, int n, int m, char **grid)
{
    bool w_flag = true;
    bool b_flag = true;

    if (x > 0)
    {
        if (grid[x - 1][y] == 'W')
            w_flag = false;
        else if (grid[x - 1][y] == 'B')
            b_flag = false;
    }

    if (x < n - 1)
    {
        if (grid[x + 1][y] == 'W')
            w_flag = false;
        else if (grid[x + 1][y] == 'B')
            b_flag = false;
    }

    if (y > 0)
    {
        if (grid[x][y - 1] == 'W')
            w_flag = false;
        else if (grid[x][y - 1] == 'B')
            b_flag = false;
    }

    if (y < m - 1)
    {
        if (grid[x][y + 1] == 'W')
            w_flag = false;
        else if (grid[x][y + 1] == 'B')
            b_flag = false;
    }

    if (w_flag || b_flag)
    {
        grid[x][y] = w_flag ? 'W' : 'B';

        if (!getNextSafe(x, y, n, m, grid))
        {
            for (int i = 0; i < n; i++)
                cout << grid[i] << endl;
            return true;
        }

        solve(x, y, n, m, grid);
    }

    else
        grid[x][y] = '.';

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    char **grid = new char *[n];
    for (int i = 0; i < n; i++)
        grid[i] = new char[m + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
        grid[i][m] = 0;
    }

    int x = 0, y = 0;
    getNextSafe(x, y, n, m, grid);
    solve(x, y, n, m, grid);
}