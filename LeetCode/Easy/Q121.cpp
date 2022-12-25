#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int maxProfit(vector<int>& prices)
        {
            int maxProfit = 0;
            int minHistory = prices[0];
            for (int i = 0; i < prices.size(); i++) {
                maxProfit = max(maxProfit, prices[i] - minHistory);
                minHistory = min(minHistory, prices[i]);
            }
            return max(maxProfit, 0);
        }
    };
};

TEST(LeetCodeEnv, Q121_1)
{
    Solution solution;
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    int ans = solution.maxProfit(prices);
    int exceptAns = 5;
    ASSERT_EQ(ans, exceptAns);
}