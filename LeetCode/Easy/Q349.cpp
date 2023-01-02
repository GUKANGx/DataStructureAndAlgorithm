#include "main.h"

using namespace std;
using namespace Utils::MyLinkedList;

namespace {
    class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
        {
            unordered_set<int> table {nums1.begin(), nums1.end()};
            vector<int> ans;
            for (const auto &n : nums2) {
                if (table.find(n) != table.end()) {
                    ans.emplace_back(n);
                    table.erase(n);
                }
            }
            return  ans;
        }
    };
};

TEST(LeetCodeEnv, Q349_1)
{
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    auto ans = solution.intersection(nums1, nums2);
    vector<int> exceptAns = {2};
    ASSERT_EQ(ans.size(), exceptAns.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i], exceptAns[i]);
    }
}