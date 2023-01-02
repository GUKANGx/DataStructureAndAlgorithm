#include "main.h"

using namespace std;
using namespace Utils::MyBinaryTree;

namespace {
    class Solution {
    public:
        string toHex(int num)
        {
            if (num == 0) {
                return "0";
            }
            const vector<char> table = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                                          'a', 'b', 'c', 'd', 'e', 'f'};
            uint32_t tmp = num;
            string ans = "";
            while (tmp != 0) {
                ans = table[tmp & 0x0f] + ans;
                tmp >>= 4;
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q405_1)
{
    Solution solution;
    string ans = solution.toHex(26);
    ASSERT_EQ(ans, "1a");
}