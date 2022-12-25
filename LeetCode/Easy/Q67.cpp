#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        string addBinary(string a, string b)
        {
            string ans;
            int add = 0;
            int lenA = a.size();
            int lenB = b.size();
            int i = lenA - 1;
            int j = lenB - 1;
            while (i >= 0 || j >= 0) {
                int tmp = add;
                if (i >= 0) {
                    tmp += a[i--] - '0';
                }
                if (j >= 0) {
                    tmp += b[j--] - '0';
                }
                ans = static_cast<char>('0' + tmp % 2) + ans;
                add = tmp / 2;
            }
            if (add != 0) {
                ans = static_cast<char>('0' + add) + ans;
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q67_1)
{
    string a = "11", b = "1";
    Solution solution;
    auto ans = solution.addBinary(a, b);
    ASSERT_EQ(ans, "100");
}

