#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        void swapStr(string &s, int start, int stop)
        {
            while (start < stop) {
                swap(s[start++], s[stop--]);
            }
        }

        string reverseStr(string s, int k)
        {
            int len = s.size();
            int i = 0, j = 2 * k;
            while (j < len) {
                swapStr(s, i, j - k - 1);
                i = j;
                j += 2 * k;
            }
            int rest = len - i;
            if (rest == 0) {
                i = j;
            } else if (rest < k) {
                j = len - 1;
            } else {
                j = i + k - 1;
            }
            swapStr(s, i, j);
            return s;
        }
    };
};

TEST(LeetCodeEnv, Q541_1)
{
    Solution solution;
    string ans = solution.reverseStr("abcdefg", 2);
    ASSERT_EQ(ans, "bacdfeg");
}