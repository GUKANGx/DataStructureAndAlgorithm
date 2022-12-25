#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        bool isHappy(int n)
        {
            unordered_set<int> table;
            while (n != 1) {
                int tmp = n;
                n = 0;
                while (tmp != 0) {
                    int x = tmp % 10;
                    tmp /= 10;
                    n += x * x;
                }
                if (table.find(n) != table.end()) {
                    return false;
                } else {
                    table.insert(n);
                }
            }
            return true;
        }
    };
};

TEST(LeetCodeEnv, Q202_1)
{
    Solution solution;
    int ans = solution.isHappy(19);
    ASSERT_TRUE(ans);
}