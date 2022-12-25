#include "main.h"

using namespace std;

namespace {
    class Solution
    {
    public:
        vector<int> numberOfLines(vector<int>& widths, string s)
        {
            const int maxCountLine = 100;
            int currCount = 0;
            vector<int> ans(2, 0);
            for (const auto & ch : s) {
                int index = ch - 'a';
                int count = widths[index];
                if (count + currCount > maxCountLine) {
                    ans[0]++;
                    currCount = count;
                } else {
                    currCount += count;
                }
            }
            if (currCount > 0) {
                ans[0]++;
            }
            ans[1] = currCount;
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q806_1)
{
    vector<int> widths = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string s = "abcdefghijklmnopqrstuvwxyz";
    Solution solution;
    vector<int> ans = solution.numberOfLines(widths, s);
    ASSERT_EQ(ans[0], 3);
    ASSERT_EQ(ans[1], 60);
}

