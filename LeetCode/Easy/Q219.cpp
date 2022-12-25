#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k)
        {
            unordered_map<int, int> table;
            int len = nums.size();
            for (int i = 0; i < len; i++) {
                if (table.find(nums[i]) != table.end() && i - table[nums[i]] <= k) {
                    return true;
                }
                table[nums[i]] = i;
            }
            return false;
        }
    };
};

TEST(LeetCodeEnv, Q219_1)
{
    Solution solution;
    vector<int> nums = {1,2,3,1};
    int k = 3;
    bool ans = solution.containsNearbyDuplicate(nums, k);
    ASSERT_TRUE(ans);
}