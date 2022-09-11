#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int removeElement(vector<int>& nums, int val)
        {
            int i = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] != val) {
                    nums[i++] = nums[j];
                }
            }
            return i;
        }
    };
};

TEST(leetcode, Q27_1)
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    Solution solution;
    auto ans = solution.removeElement(nums, val);
    vector<int> exceptAns = {2, 2};
    ASSERT_EQ(ans, exceptAns.size());
    for (int i = 0; i < ans; i++) {
        ASSERT_EQ(nums[i], exceptAns[i]);
    }
}

