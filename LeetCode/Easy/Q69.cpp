#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int mySqrt(int x)
        {
            int left = 0, right = x;
            int ans = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long tmp = (long long)mid * mid;
                if (tmp == x) {
                    ans = mid;
                    break;
                } else if (tmp > x) {
                    right = mid - 1;
                } else {
                    ans = mid;
                    left = mid + 1;
                }
            }
            return ans;
        }
    };
};

TEST(leetcode, Q69_1)
{
    int x = 8;
    Solution solution;
    auto ans = solution.mySqrt(x);
    ASSERT_EQ(ans, 2);
}

