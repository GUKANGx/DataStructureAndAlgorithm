#include "main.h"

using namespace std;

namespace {
    class Solution
    {
    public:
        string intToRoman(int num)
        {
            vector<pair<int, string>> table = {
                    {1000, "M"},
                    {900, "CM"},
                    {500, "D"},
                    {400, "CD"},
                    {100, "C"},
                    {90, "XC"},
                    {50, "L"},
                    {40, "XL"},
                    {10, "X"},
                    {9, "IX"},
                    {5, "V"},
                    {4, "IV"},
                    {1, "I"},
            };

            int i = 0;
            string ans = "";
            while (num > 0) {
                if (num >= table[i].first) {
                    num -= table[i].first;
                    ans += table[i].second;
                } else {
                    i++;
                }
            }
            return ans;
        }
    };
};

TEST(leetcode, Q12_1)
{
    int num = 1994;
    Solution s;
    ASSERT_EQ(s.intToRoman(num), "MCMXCIV");
}

