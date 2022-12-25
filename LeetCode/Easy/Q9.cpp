#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        bool isPalindrome(int x)
        {
            if (x < 0) {
                return false;
            }
            int tmp = x;
            long long rX = 0;
            while (tmp != 0) {
                rX *= 10;
                rX += tmp % 10;
                tmp /= 10;
            }
            return rX == x;
        }
    };
};

TEST(LeetCodeEnv, Q9_1)
{
    int x = 121;
    Solution solution;
    ASSERT_EQ(solution.isPalindrome(x), true);
}

