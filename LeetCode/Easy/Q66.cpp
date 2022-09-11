#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        vector<int> plusOne(vector<int>& digits)
        {
            int add = 1;
            for (int i = digits.size() - 1; i >= 0; i--) {
                int tmp = digits[i] + add;
                digits[i] = tmp % 10;
                add = tmp / 10;
                if (add == 0) {
                    break;
                }
            }
            if (add != 0) {
                digits.insert(digits.begin(), add);
            }
            return digits;
        }
    };
};

TEST(leetcode, Q66_1)
{
    vector<int> digits = {1, 2, 3};
    Solution solution;
    auto ans = solution.plusOne(digits);
    vector<int> exceptAns = {1, 2, 4};
    ASSERT_EQ(ans.size(), exceptAns.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i], exceptAns[i]);
    }
}

