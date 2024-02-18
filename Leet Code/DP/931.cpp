#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> prev(n, 0), curr(n, 0);

        for (int i = 0; i < n; i++)
            prev[i] = matrix[n - 1][i];

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                    curr[j] = min(prev[j], prev[j + 1]);
                else if (j == n - 1)
                    curr[j] = min(prev[j - 1], prev[j]);
                else
                    curr[j] = min(min(prev[j - 1], prev[j]), prev[j + 1]);
                curr[j] += matrix[i][j];
            }

            prev = curr;
        }

        int min = prev[0];
        for (int i = 0; i < n; i++)
            if (prev[i] < min)
                min = prev[i];

        return min;
    }
};

int main()
{
    vector<vector<int>> data = {
        {-19, 57},
        {-40, 5},
    };

    cout << Solution().minFallingPathSum(data);
}
