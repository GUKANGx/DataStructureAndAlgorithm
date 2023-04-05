#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
        {
            if (r * c != mat.size() * mat[0].size()) {
                return mat;
            }
            vector<vector<int>> ans(r, vector<int>(c));
            int i = 0;
            int cC = mat[0].size();
            int total = r * c;
            while (i < total) {
                ans[i / c][i % c] = mat[i / cC][i % cC];
                i++;
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q566_1)
{
    Solution solution;
    vector<vector<int>> mat = {
            {1, 2},
            {3, 4},
    };
    int r = 1;
    int c = 4;
    auto ans = solution.matrixReshape(mat, r, c);
    ASSERT_EQ(ans.size(), r);
    for (const auto &v : ans) {
        ASSERT_EQ(v.size(), c);
    }
    int i = 0;
    while (i < r * c) {
        ASSERT_EQ(mat[i / 2][i % 2], ans[i / c][i % c]);
        i++;
    }
}