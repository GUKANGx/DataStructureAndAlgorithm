#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target)
        {
            std::vector<int> ans(2);
            int i = 0;
            int j = numbers.size() - 1;
            while (i < j) {
                int tmp = numbers[i] + numbers[j];
                if (tmp > target) {
                    j--;
                } else if (tmp < target) {
                    i++;
                } else {
                    break;
                }
            }
            ans[0] = i + 1;
            ans[1] = j + 1;
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q167_1)
{
    Solution solution;
    std::vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> ansExpect = {1, 2};
    auto ans = solution.twoSum(numbers, target);
    ASSERT_EQ(ans.size(), ansExpect.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i], ansExpect[i]);
    }
}

