#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int n = nums[0], m = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > n)
                n = nums[i];

            if (nums[i] < m)
                m = nums[i];
        }

        vector<int> dp(n - m + 1, -1);
        vector<int> counts(n - m + 1, 0);

        for (int i = 0; i < nums.size(); i++)
            counts[nums[i] - m] += nums[i];

        if (counts.size() == 1)
            return counts[0];

        dp[n - m] = counts[n - m];
        dp[n - m - 1] = max(counts[n - m - 1], counts[n - m]);

        for (int i = n - m - 2; i >= 0; i--)
            dp[i] = max(dp[i + 1], counts[i] + dp[i + 2]);

        return dp[0];
    }
};

int main()
{
    vector<int> query = {1};

    cout << Solution().deleteAndEarn(query);
}
