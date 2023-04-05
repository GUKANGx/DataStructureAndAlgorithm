#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        bool detectCapitalUse(string word)
        {
            int UpperCount = 0;
            bool isAllLower = true;
            for (const auto &c : word) {
                if (isupper(c)) {
                    isAllLower = false;
                    UpperCount++;
                }
            }
            return isAllLower || UpperCount == word.size() || (UpperCount == 1 && isupper(word[0]));
        }
    };
};

TEST(LeetCodeEnv, Q520_1)
{
    Solution solution;
    bool ans = solution.detectCapitalUse("FlaG");
    ASSERT_EQ(ans, false);
}