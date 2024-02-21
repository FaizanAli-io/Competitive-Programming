#include <iostream>
using namespace std;

class Solution
{
public:
    long int tribonacci(int n)
    {
        long int *dp = new long int[3]{0, 1, 1};

        for (int i = 0; i < n; i++)
        {
            long int temp = dp[0] + dp[1] + dp[2];
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = temp;
        }

        return dp[0];
    }
};

int main()
{
    int query = 5;

    cout << Solution().tribonacci(query);
}
