#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int searchInsert(vector<int>& nums, int target)
        {
            int left = 0, right = nums.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else if (nums[mid] > target) {
                    right = mid;
                }
            }
            return right;
        }
    };
};

TEST(LeetCodeEnv, Q35_1)
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    Solution solution;
    auto ans = solution.searchInsert(nums, target);
    ASSERT_EQ(ans, 1);
}

