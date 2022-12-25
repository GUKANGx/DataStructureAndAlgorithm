#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        vector<int> arrayRankTransform(vector<int>& arr)
        {
            vector<int> arrSort(arr.begin(), arr.end());
            sort(arrSort.begin(), arrSort.end(), [](const int &a, const int &b) {
                return a < b;
            });
            unordered_map<int, int> indexMap;
            int index = 0;
            for (int i = 0; i < arrSort.size(); i++) {
                if (i == 0 || arrSort[i] != arrSort[i - 1]) {
                    indexMap[arrSort[i]] = index++;
                }
            }
            vector<int> ans(arr.size());
            for (int i = 0; i < arr.size(); i++) {
                ans[i] = indexMap[arr[i]] + 1;
            }
            return std::move(ans);
        }
    };
};

TEST(LeetCodeEnv, Q1331_1)
{
    vector<int> arr = {40, 10, 20, 30};
    Solution solution;
    auto ans = solution.arrayRankTransform(arr);
    vector<int> exceptAns = {4, 1, 2, 3};
    ASSERT_EQ(ans.size(), exceptAns.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i], exceptAns[i]);
    }
}

