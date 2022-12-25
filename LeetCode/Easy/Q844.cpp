#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        string Helper(string s)
        {
            int len = s.size();
            vector<char> stack(len);
            int stackLen = 0;
            for (int i = 0; i < len; i++) {
                if (s[i] == '#') {
                    if (stackLen != 0) {
                        stackLen--;
                    }
                    continue;
                }
                stack[stackLen++] = s[i];
            }
            return {stack.begin(), stack.begin() + stackLen};
        }

        bool backspaceCompare(string s, string t)
        {
            string sNew = Helper(s);
            string tNes = Helper(t);
            return sNew == tNes;
        }
    };
};

TEST(LeetCodeEnv, Q844_1)
{
    string s = "y#fo##f";
    string t = "y#f#o##f";
    Solution solution;
    bool ans = solution.backspaceCompare(s, t);
    ASSERT_EQ(ans, true);
}

