#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        bool isIsomorphicHelper(string s, string t)
        {
            unordered_map<char, char> table;
            int len = s.size();
            for (int i = 0; i < len; i++) {
                if (table.find(s[i]) == table.end()) {
                    table[s[i]] = t[i];
                } else if (table[s[i]] != t[i]) {
                    return false;
                }
            }
            return true;
        }

        bool isIsomorphic(string s, string t)
        {
            if (s.size() != t.size()) {
                return false;
            }
            return isIsomorphicHelper(s, t) && isIsomorphicHelper(t, s);
        }
    };
};

TEST(LeetCodeEnv, Q205_1)
{
    Solution solution;
    bool ans = solution.isIsomorphic("egg", "add");
    ASSERT_EQ(ans, true);
}