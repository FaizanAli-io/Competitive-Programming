#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int largestSquare(vector<vector<char>> &matrix, vector<vector<int>> &dp, int i, int j, int n, int m)
    {
        if (i == n - 1 || j == m - 1)
            return matrix[i][j] == '1';

        if (matrix[i][j] == '0')
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int a = largestSquare(matrix, dp, i + 1, j, n, m);
        int b = largestSquare(matrix, dp, i, j + 1, n, m);
        int c = largestSquare(matrix, dp, i + 1, j + 1, n, m);

        return dp[i][j] = 1 + min(min(a, b), c);
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int max = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int res = largestSquare(matrix, dp, i, j, n, m);
                if (res > max)
                    max = res;
            }
        }

        return max * max;
    }
};

int main()
{
    vector<vector<char>> data = {
        {'1', '1', '1'},
        {'1', '1', '1'},
        {'1', '1', '1'},
    };

    cout << Solution().maximalSquare(data);
}
