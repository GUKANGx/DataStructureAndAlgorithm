#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int singleNumber(vector<int>& nums)
        {
            if (nums.empty()) {
                return 0;
            }
            unordered_map<int, int> countTable;
            for (auto &i : nums) {
                if (countTable.find(i) == countTable.end()) {
                    countTable[i] = 1;
                } else {
                    countTable[i]++;
                }
            }
            for (auto &iter : countTable) {
                if (iter.second == 1) {
                    return iter.first;
                }
            }
            return 0;
        }
    };
};

TEST(leetcode, Q136_1)
{
    Solution solution;
    vector<int> num = { 2, 2, 1 };
    int ans = solution.singleNumber(num);
    int exceptAns = 1;
    ASSERT_EQ(ans, exceptAns);
}