#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void DFS(vector<vector<int>> &isConnected, vector<bool> &visited, int i, int n)
    {
        visited[i] = 1;

        for (int j = 0; j < n; j++)
            if (isConnected[i][j])
                if (!visited[j])
                    DFS(isConnected, visited, j, n);
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                DFS(isConnected, visited, i, n);
                count++;
            }
        }

        return count;
    }
};

int main()
{
    vector<vector<int>> data = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
    };

    cout << Solution().findCircleNum(data);
}
