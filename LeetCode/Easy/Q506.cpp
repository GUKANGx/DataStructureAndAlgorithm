#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        vector<string> table = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<string> findRelativeRanks(vector<int>& score)
        {
            vector<pair<int, int>> scoreSorted(score.size());
            for (int i = 0; i < score.size(); i++) {
                scoreSorted[i] = {score[i], i};
            }
            sort(scoreSorted.rbegin(), scoreSorted.rend(),
                 [](const pair<int, int>& a, const pair<int, int>& b){
                return a.first < b.first;
            });

            vector<string> ans(score.size());
            stringstream ss;
            for (int i = 0; i < score.size(); i++) {
                if (i < table.size()) {
                    ans[scoreSorted[i].second] = table[i];
                } else {
                    ss.clear();
                    ss << (i + 1);
                    ss >> ans[scoreSorted[i].second];
                }
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q506_1)
{
    Solution solution;
    vector<int> score = {5,4,3,2,1};
    auto ans = solution.findRelativeRanks(score);
    decltype(ans) exceptAns = {"Gold Medal","Silver Medal","Bronze Medal","4","5"};
    ASSERT_EQ(ans.size(), exceptAns.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i], exceptAns[i]);
    }
}