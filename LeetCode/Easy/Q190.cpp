#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        uint32_t reverseBits(uint32_t n)
        {
            uint32_t ans = 0;
            for (int i = 0; i < 32; i++) {
                ans <<= 1;
                ans |= n & 0x01;
                n >>= 1;
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q190_1)
{
    Solution solution;
    auto ans = solution.reverseBits(43261596);
    ASSERT_EQ(ans, 964176192 );
}