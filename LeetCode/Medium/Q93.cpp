#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        void restoreIpAddressesHelper(string& s, vector<string>& ans)
        {

        }

        vector<string> restoreIpAddresses(string s)
        {
            vector<string> ans;
            restoreIpAddressesHelper(s, ans);
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q93_1)
{
    Solution solution;
    string s = "25525511135";
    vector<string> ansExpect = {"255.255.11.135","255.255.111.35"};
    auto ans = solution.restoreIpAddresses(s);
    ASSERT_EQ(ans.size(), ansExpect.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i], ansExpect[i]);
    }
}

