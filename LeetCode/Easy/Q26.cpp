#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int removeDuplicates(vector<int>& nums)
        {
            int i = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] != nums[i]) {
                    nums[++i] = nums[j];
                }
            }
            return i + 1;
        }
    };
};

TEST(leetcode, Q26_1)
{
    vector<int> nums = {1, 1, 2};
    Solution solution;
    auto ans = solution.removeDuplicates(nums);
    vector<int> exceptAns = {1, 2};
    ASSERT_EQ(ans, exceptAns.size());
    for (int i = 0; i < ans; i++) {
        ASSERT_EQ(nums[i], exceptAns[i]);
    }
}

