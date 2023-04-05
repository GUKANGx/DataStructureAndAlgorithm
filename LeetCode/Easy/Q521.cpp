#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int findLUSlength(string a, string b)
        {
            int lenA = a.size();
            int lenB = b.size();
            if (a != b) {
                return lenA > lenB ? lenA : lenB;
            }
            return -1;
        }
    };
};

TEST(LeetCodeEnv, Q521_1)
{
    Solution solution;
    int ans = solution.findLUSlength("aba", "cdc");
    ASSERT_EQ(ans, 3);
}