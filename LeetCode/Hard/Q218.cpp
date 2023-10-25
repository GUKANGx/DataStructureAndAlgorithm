#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& buildings, int left, int right)
        {
            if (left == right)
            {
                return { { buildings[left][0], buildings[left][2] },
                         { buildings[left][1], 0 } };
            }

            // divide
            int mid = (left + right) / 2;
            vector<vector<int>> left_res = merge(buildings, left, mid);
            vector<vector<int>> right_res = merge(buildings, mid + 1, right);

            // merge
            int i = 0, j = 0;
            int h_left = 0, h_right = 0;
            vector<vector<int>> ans;
            while (i < left_res.size() || j < right_res.size())
            {
                long long x_left = i < left_res.size() ? left_res[i][0] : LLONG_MAX;
                long long x_right = j < right_res.size() ? right_res[j][0] : LLONG_MAX;
                long long x_smallest = INT_MAX;
                if (x_left < x_right)
                {
                    x_smallest = x_left;
                    h_left = left_res[i][1];
                    i++;
                }
                else if (x_left > x_right)
                {
                    x_smallest = x_right;
                    h_right = right_res[j][1];
                    j++;
                }
                else
                {
                    x_smallest = x_left;
                    h_left = left_res[i][1];
                    h_right = right_res[j][1];
                    i++;
                    j++;
                }
                int h_highest = max(h_left, h_right);
                if (!ans.empty() && ans.back()[1] == h_highest) continue;
                ans.push_back({ (int)x_smallest, h_highest });
            }

            return ans;
        }

        // divide and merge
        vector<vector<int>> method_1(vector<vector<int>>& buildings)
        {
            int len = buildings.size();
            if (len == 0) return {};
            return merge(buildings, 0, len - 1);
        }

        // avl tree
        vector<vector<int>> method_2(vector<vector<int>>& buildings)
        {
            vector<vector<int>> position;
            for (auto& b : buildings)
            {
                // This is very important
                // left < 0
                position.push_back({ b[0], -b[2]});
                // right > 0
                position.push_back({ b[1], b[2]});
            }
            sort(position.begin(), position.end(), [](const vector<int>& a, const vector<int>& b) {
                if (a[0] != b[0]) return a[0] < b[0];
                return a[1] < b[1];
            });

            vector<vector<int>> ans;
            multiset<int> heights({ 0 });
            for (auto& p : position)
            {
                if (p[1] < 0) heights.insert(-p[1]);
                else heights.erase(heights.find(p[1]));

                if (heights.empty()) continue;
                if (!ans.empty() && ans.back()[1] == *heights.rbegin()) continue;

                ans.push_back({ p[0], *heights.rbegin() });
            }

            return ans;
        }

        // max heap
        vector<vector<int>> method_3(vector<vector<int>>& buildings)
        {
            vector<vector<int>> position;
            for (auto& b : buildings)
            {
                // This is very important
                // left < 0 push {left, -height, right}
                position.push_back({ b[0], -b[2], b[1] });
                // right > 0 push {left, height, right}
                position.push_back({ b[1], b[2], 0 });
            }
            sort(position.begin(), position.end(), [](const vector<int>& a, const vector<int>& b) {
                if (a[0] != b[0]) return a[0] < b[0];
                return a[1] < b[1];
            });

            vector<vector<int>> ans;
            // {height, right}
            priority_queue<pair<int, long long>, vector<pair<int, long long>>, less<pair<int, long long>>> max_heap;
            max_heap.push({ 0, LLONG_MAX });
            for (auto& p : position)
            {
                while (p[0] >= max_heap.top().second)
                {
                    max_heap.pop();
                }
                if (p[1] < 0)
                {
                    max_heap.push({ -p[1], p[2] });
                }
                if (!ans.empty() && ans.back()[1] == max_heap.top().first) continue;
                ans.push_back({ p[0], max_heap.top().first });
            }
            return ans;
        }

        vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
        {
            // method_1
            // return method_1(buildings);
            // method_2
            // return method_2(buildings);
            // method_3
            return method_3(buildings);
        }
    };
};

TEST(LeetCodeEnv, Q218_1)
{
    Solution solution;
    std::vector<std::vector<int>> buildings = {{0, 2, 3}, {2, 5, 3}};
    std::vector<std::vector<int>> ansExpect = {{0, 3}, {5, 0}};
    auto ans = solution.getSkyline(buildings);
    ASSERT_EQ(ans.size(), ansExpect.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i].size(), ansExpect[i].size());
        for (int j = 0; j < ans[i].size(); j++) {
            ASSERT_EQ(ans[i][j], ansExpect[i][j]);
        }
    }
}

