#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int lengthOfLastWord(string s)
        {
            int ans = 0;
            int i = s.size() - 1;
            while (i >= 0 && !isalpha(s[i])) {
                i--;
            }
            while (i >= 0 && isalpha(s[i])) {
                ans++;
                i--;
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q58_1)
{
    string s = "Hello World";
    Solution solution;
    auto ans = solution.lengthOfLastWord(s);
    ASSERT_EQ(ans, 5);
}

