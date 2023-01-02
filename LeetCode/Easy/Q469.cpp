#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
        {
            unordered_map<int, int> table;
            stack<int> s;
            for (const auto &n : nums2) {
                while (!s.empty() && n > s.top()) {
                    table.insert({s.top(), n});
                    s.pop();
                }
                s.push(n);
            }
            vector<int> ans;
            for (const auto &n : nums1) {
                auto it = table.find(n);
                if (it == table.end()) {
                    ans.emplace_back(-1);
                } else {
                    ans.emplace_back(it->second);
                }
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q469_1)
{
    Solution solution;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    auto ans = solution.nextGreaterElement(nums1, nums2);
    vector<int> exceptAns = {-1, 3, -1};
    ASSERT_EQ(ans.size(), exceptAns.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i], exceptAns[i]);
    }
}