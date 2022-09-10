#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            vector<int> ans(2, -1);
            unordered_map<int, int> indexMap;
            int len = nums.size();
            for (int i = 0; i < len; i++) {
                indexMap[nums[i]] = i;
            }
            for (int i = 0; i < len; i++) {
                int tmp = target - nums[i];
                auto ret = indexMap.find(tmp);
                if (ret == indexMap.end() || ret->second == i) {
                    continue;
                }
                ans[0] = i;
                ans[1] = ret->second;
                break;
            }
            return ans;
        }
    };
};

TEST(leetcode, Q1_1)
{
    int target = 9;
    vector<int> nums = {2, 7, 11, 15};
    Solution solution;
    vector<int> ans = solution.twoSum(nums, target);
    ASSERT_EQ(ans[0], 0);
    ASSERT_EQ(ans[1], 1);
}

