#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int romanToInt(string s)
        {
            unordered_map<string, int> table = {
                    {"I", 1},
                    {"IV", 4},
                    {"V", 5},
                    {"IX", 9},
                    {"X", 10},
                    {"XL", 40},
                    {"L", 50},
                    {"XC", 90},
                    {"C", 100},
                    {"CD", 400},
                    {"D", 500},
                    {"CM", 900},
                    {"M", 1000},
            };

            int len = s.size();
            int ans = 0;
            for (int i = len - 1; i >= 0; i--) {
                if (i > 0 && table.find(s.substr(i - 1, 2)) != table.end()) {
                    ans += table[s.substr(i - 1, 2)];
                    i--;
                    continue;
                }
                ans += table[s.substr(i, 1)];
            }
            return ans;
        }
    };
};

TEST(leetcode, Q13_1)
{
    string str = "III";
    Solution s;
    ASSERT_EQ(s.romanToInt(str), 3);
}

