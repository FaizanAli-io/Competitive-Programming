#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();

        vector<vector<int>> reverse(n);
        vector<int> degreeList(n);
        vector<int> terminals;

        for (int i = 0; i < n; i++)
        {
            degreeList[i] = graph[i].size();
            for (int j = 0; j < degreeList[i]; j++)
                reverse[graph[i][j]].push_back(i);

            if (degreeList[i] == 0)
                terminals.push_back(i);
        }

        int m = terminals.size();
        for (int i = 0; i < m; i++)
        {
            vector<int> nodes = reverse[terminals[i]];
            for (int node : nodes)
            {
                degreeList[node]--;
                if (degreeList[node] == 0)
                    terminals.push_back(node);
            }

            m = terminals.size();
        }

        sort(terminals.begin(), terminals.end());

        return terminals;
    }
};

int main()
{
    vector<vector<int>> data = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {},
    };

    vector<int> res = Solution().eventualSafeNodes(data);

    for (int node : res)
        cout << node << endl;
}
