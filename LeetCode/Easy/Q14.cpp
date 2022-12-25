#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs)
        {
            if (strs.empty() || strs[0].empty()) {
                return "";
            }
            string ans;
            int i = 0;
            int len = strs[0].size();
            while (i < len) {
                char ch = strs[0][i];
                for (int j = 1; j < strs.size(); j++) {
                    if (i >= strs[j].size() || ch != strs[j][i]) {
                        i = len;
                        break;
                    }
                }
                if (i != len) {
                    ans += ch;
                    i++;
                }
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q14_1)
{
    vector<string> strs =  {"a"};
    Solution solution;
    string ans = solution.longestCommonPrefix(strs);
    ASSERT_EQ(ans, "a");
}

