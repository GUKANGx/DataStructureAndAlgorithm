#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int hammingWeight(uint32_t n)
        {
            int ans = 0;
            while (n != 0) {
                n &= n - 1;
                ans++;
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q191_1)
{
    Solution solution;
    int ans = solution.hammingWeight(11);
    ASSERT_EQ(ans, 3);
}