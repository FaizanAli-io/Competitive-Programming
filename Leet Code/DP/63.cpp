#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int solver(vector<vector<int>> &obstacleGrid, vector<vector<int>> &solutionMap, int i, int j, int n, int m)
    {
        if (i >= n || j >= m || obstacleGrid[i][j])
            return 0;

        if (i == n - 1 && j == m - 1)
            return 1;

        if (solutionMap[i][j])
            return solutionMap[i][j];

        int a = 0, b = 0;

        if (i < n - 1)
            a = solver(obstacleGrid, solutionMap, i + 1, j, n, m);

        if (j < m - 1)
            b = solver(obstacleGrid, solutionMap, i, j + 1, n, m);

        return solutionMap[i][j] = a + b;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> solutionMap(n, vector<int>(m, 0));
        return solver(obstacleGrid, solutionMap, 0, 0, n, m);
    }
};

int main()
{
    vector<vector<int>> data = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };

    cout << Solution().uniquePathsWithObstacles(data);
}
