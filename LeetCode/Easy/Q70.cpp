#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int climbStairs(int n)
        {
            vector<int> dp(n + 1);
            dp[0] = 1;
            dp[1] = 1;
            for (int i = 2; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
    };
};

TEST(leetcode, Q70_1)
{
    int n = 2;
    Solution solution;
    auto ans = solution.climbStairs(n);
    ASSERT_EQ(ans, 2);
}

