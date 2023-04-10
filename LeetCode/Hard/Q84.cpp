#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int largestRectangleArea(vector<int>& heights)
        {
            int len = heights.size();
            vector<int> left(len, -1);
            vector<int> right(len, len);

            stack<int> s;
            for (int i = 0; i < len; i++) {
                while (!s.empty() && heights[s.top()] >= heights[i]) {
                    right[s.top()] = i;
                    s.pop();
                }
                if (!s.empty()) {
                    left[i] = s.top();
                }
                s.push(i);
            }

//            s = stack<int>();
//            for (int i = len - 1; i > -1; i--) {
//                while (!s.empty() && heights[s.top()] >= heights[i]) {
//                    s.pop();
//                }
//                if (!s.empty()) {
//                    right[i] = s.top();
//                }
//                s.push(i);
//            }

            int ans = 0;
            for (int i = 0; i < len; i++) {
                int area = heights[i] * (right[i] - left[i] - 1);
                ans = area > ans ? area : ans;
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q84_1)
{
    Solution solution;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int ans = solution.largestRectangleArea(heights);
    ASSERT_EQ(ans, 10);
}

