#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        vector<vector<int>> generate(int numRows)
        {
            vector<vector<int>> ans({{1}});
            for (int i = 1; i < numRows; i++) {
                ans.push_back({});
                for (int j = 0; j <= i; j++) {
                    int s0 = j - 1;
                    int s1 = j;
                    if (s0 >= 0 && s0 < ans[i - 1].size() && s1 >= 0 && s1 < ans[i - 1].size()) {
                        ans[i].push_back(ans[i - 1][s0] + ans[i - 1][s1]);
                    } else {
                        ans[i].push_back(1);
                    }
                }
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q118_1)
{
    Solution solution;
    int numRows = 5;
    vector<vector<int>> ans = solution.generate(numRows);
    vector<vector<int>> exceptAns = { { 1 }, { 1, 1 }, { 1, 2, 1 }, { 1, 3, 3, 1 }, { 1, 4, 6, 4, 1 } };
    ASSERT_EQ(ans.size(), exceptAns.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i].size(), exceptAns[i].size());
        for (int j = 0; j < ans[i].size(); j++) {
            ASSERT_EQ(ans[i][j], exceptAns[i][j]);
        }
    }
}