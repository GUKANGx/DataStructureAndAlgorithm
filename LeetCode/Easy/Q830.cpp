#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        vector<vector<int>> largeGroupPositions(string s)
        {
            const int k = 3;
            size_t len = s.size();
            int left = 0, right = 0;
            vector<vector<int>> ans;
            while (right < len) {
                if (s[left] == s[right]) {
                    right++;
                } else {
                    left = right;
                }
                if (right - left == k) {
                    ans.push_back({left, right - 1});
                } else if (right - left > k) {
                    ans.back()[1] = right - 1;
                }
            }
            return ans;
        }
    };
};

TEST(leetcode, Q830_1)
{
    string s = "abcdddeeeeaabbbcd";
    Solution solution;
    vector<vector<int>> ans = solution.largeGroupPositions(s);
    vector<vector<int>> exceptAns = {{3, 5}, {6, 9}, {12, 14}};
    ASSERT_EQ(ans.size(), exceptAns.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i].size(), 2);
        ASSERT_EQ(ans[i].size(), exceptAns[i].size());
        ASSERT_EQ(ans[i][0], exceptAns[i][0]);
        ASSERT_EQ(ans[i][1], exceptAns[i][1]);
    }
}

