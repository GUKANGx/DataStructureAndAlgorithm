#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int titleToNumber(string columnTitle)
        {
            constexpr int mul = 26;
            int ans = 0;
            for (auto it = columnTitle.cbegin(); it != columnTitle.cend(); it++) {
                ans *= mul;
                ans += (*it) - 'A' + 1;
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q171_1)
{
    Solution solution;
    string columnTitle = "AB";
    int ans = solution.titleToNumber(columnTitle);
    ASSERT_EQ(ans, 28);
}