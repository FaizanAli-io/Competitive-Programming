#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size() - 1;

        if (nums[0] < nums[n])
            return nums[0];

        int i = 0, j = n;

        while (abs(i - j) > 1)
        {
            int k = (i + j) / 2;

            cout << i << j << k << endl;

            if (nums[i] == nums[k] || nums[k] == nums[j])
            {
                if (nums[i] == nums[j])
                {
                    i++;
                    j--;
                }
                else if (nums[k] > nums[j])
                    i = k;
                else
                    j = k;
            }
            else
            {
                if (nums[k] >= nums[j])
                    i = k;
                else
                    j = k;
            }
        }

        return nums[i] <= nums[j] ? nums[i] : nums[j];
    }
};

int main()
{
    vector<int> data = {2, 2, 2, 0, 2, 2};

    cout << Solution().findMin(data);
}
