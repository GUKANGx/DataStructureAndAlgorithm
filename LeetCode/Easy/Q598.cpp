#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int maxCount(int m, int n, vector<vector<int>>& ops)
        {
            int minX = m;
            int minY = n;
            for (const auto& op: ops) {
                minX = op[0] < minX ? op[0] : minX;
                minY = op[1] < minY ? op[1] : minY;
            }
            return minX * minY;
        }
    };
};

TEST(LeetCodeEnv, Q598_1)
{
    Solution solution;
    int m = 3, n = 3;
    std::vector<std::vector<int>> ops = {
            {2, 2}, {3, 3} };
    int ans = solution.maxCount(m, n, ops);
    ASSERT_EQ(ans, 4);
}