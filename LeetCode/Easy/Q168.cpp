#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        string convertToTitle(int columnNumber)
        {
            constexpr int div = 26;
            string ans = "";
            while (columnNumber != 0) {
                columnNumber--;
                ans = static_cast<char>('A' + columnNumber % div) + ans;
                columnNumber /= div;
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q168_1)
{
    Solution solution;

    int columnNumber = 28;
    string ans = solution.convertToTitle(columnNumber);
    ASSERT_EQ(ans, "AB");
}