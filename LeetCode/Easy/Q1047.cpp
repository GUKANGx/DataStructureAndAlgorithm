#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        string removeDuplicates(string s)
        {
            int len = s.size();
            vector<char> stack(len + 1, '\0');
            int stackLen = 0;
            for (int i = 0; i < len; i++) {
                if (stackLen == 0 || stack[stackLen - 1] != s[i]) {
                    stack[stackLen++] = s[i];
                    continue;
                }
                stackLen--;
            }
            return {stack.begin(), stack.begin() + stackLen};
        }
    };
};

TEST(leetcode, Q1047_1)
{
    string s = "abbaca";
    Solution solution;
    auto ans = solution.removeDuplicates(s);
    ASSERT_EQ(ans, "ca");
}

