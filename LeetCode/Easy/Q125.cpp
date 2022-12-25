#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        bool isPalindrome(string s)
        {
            int left = 0, right = s.size() - 1;
            while (left < right) {
                while (left < right && !isalpha(s[left]) && !isalnum(s[left])) {
                    left++;
                }
                while (left < right && !isalpha(s[right]) && !isalnum(s[right])) {
                    right--;
                }
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }
    };
};

TEST(LeetCodeEnv, Q125_1)
{
    Solution solution;
    string s = "0P";
    bool ans = solution.isPalindrome(s);
    bool exceptAns = false;
    ASSERT_EQ(ans, exceptAns);
}