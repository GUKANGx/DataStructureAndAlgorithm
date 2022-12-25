#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int majorityElement(vector<int>& nums)
        {
            unordered_map<int, int>countTable;
            int ans = -1;
            int maxCount = 0;
            for (const auto & n : nums) {
                int currCount = 0;
                if (countTable.find(n) == countTable.end()) {
                    currCount = (countTable[n] = 1);
                } else {
                    currCount = (++countTable[n]);
                }
                if (currCount >= maxCount) {
                    ans = n;
                    maxCount = currCount;
                }
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q169_1)
{
    Solution solution;
    vector<int> nums = {2,2,1,1,1,2,2};
    int ans = solution.majorityElement(nums);
    ASSERT_EQ(ans, 2);
}