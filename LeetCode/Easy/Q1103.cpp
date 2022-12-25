#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        vector<int> distributeCandies(int candies, int num_people)
        {
            vector<int> ans(num_people, 0);
            int step = 1;
            int i = 0;
            while (candies > 0) {
                ans[i] += step > candies ? candies : step;
                candies -= step;
                step++;
                i = (i + 1) % num_people;
            }
            return std::move(ans);
        }
    };
};

TEST(LeetCodeEnv, Q1103_1)
{
    int candies = 7;
    int num_people = 4;
    Solution solution;
    auto ans = solution.distributeCandies(candies, num_people);
    vector<int> exceptAns = {1, 2, 3, 1};
    ASSERT_EQ(ans.size(), exceptAns.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i], exceptAns[i]);
    }
}

