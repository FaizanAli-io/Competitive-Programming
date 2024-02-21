#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int t = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] < 0)
                {
                    t += n - j;
                    break;
                }
            }
        }

        return t;
    }
};

int main()
{
    // vector<vector<int>> data = {
    //     {4, 3, 2, -1},
    //     {3, 2, 1, -1},
    //     {1, 1, -1, -2},
    //     {-1, -1, -2, -3},
    // };

    vector<vector<int>> data = {
        {3, 2},
        {1, 0},
    };

    cout << Solution().countNegatives(data);
}
