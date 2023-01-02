#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int islandPerimeter(vector<vector<int>>& grid)
        {
            const vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            int ans = 0;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 0) {
                        continue;
                    }
                    for (int k = 0; k < dir.size(); k++) {
                        int x = i + dir[k][0];
                        int y = j + dir[k][1];
                        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
                            ans++;
                        }
                    }
                }
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q463_1)
{
    Solution solution;
    vector<vector<int>> grid = {
            {0,1,0,0},
            {1,1,1,0},
            {0,1,0,0},
            {1,1,0,0},
    };
    int ans = solution.islandPerimeter(grid);
    ASSERT_EQ(ans, 16);
}