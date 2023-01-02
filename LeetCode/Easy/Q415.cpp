#include "main.h"

using namespace std;
using namespace Utils::MyBinaryTree;

namespace {
    class Solution {
    public:
        string addStrings(string num1, string num2)
        {
            string ans = "";
            auto it1 = num1.rbegin();
            auto it2 = num2.rbegin();
            int add = 0;
            while (it1 != num1.rend() || it2 != num2.rend()) {
                int a = it1 != num1.rend() ? *(it1++) - '0' : 0;
                int b = it2 != num2.rend() ? *(it2++) - '0' : 0;
                int res = a + b + add;
                add = res / 10;
                ans = static_cast<char>(res % 10 + '0') + ans;
            }
            if (add != 0) {
                ans = static_cast<char>(add + '0') + ans;
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q415_1)
{
    Solution solution;
    string ans = solution.addStrings("11", "123");
    ASSERT_EQ(ans, "134");
}