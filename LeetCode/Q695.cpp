#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int area;
        const vector<vector<int>> dir = {{0,  1},
                                         {0,  -1},
                                         {1,  0},
                                         {-1, 0}};

        void dfs(vector<vector<int>> &grid, int currRow, int currCol) {
            int maxRow = grid.size();
            int maxCol = grid[0].size();
            area++;
            for (int i = 0; i < dir.size(); i++) {
                int nextRow = currRow + dir[i][0];
                int nextCol = currCol + dir[i][1];
                if (nextRow < 0 || nextRow >= maxRow || nextCol < 0 || nextCol >= maxCol ||
                    grid[nextRow][nextCol] != 1) {
                    continue;
                }
                grid[nextRow][nextCol] = 2;
                dfs(grid, nextRow, nextCol);
            }
        }

        int maxAreaOfIsland(vector<vector<int>> &grid) {
            int maxRow = grid.size();
            int maxCol = grid[0].size();

            int ans = 0;
            for (int i = 0; i < maxRow; i++) {
                for (int j = 0; j < maxCol; j++) {
                    if (grid[i][j] != 1) {
                        continue;
                    }
                    grid[i][j] = 2;
                    area = 0;
                    dfs(grid, i, j);
                    ans = max(area, ans);
                }
            }

            return ans;
        }
    };
};

TEST(leetcode, Q695_1)
{
    vector<vector<int>> grid = {
            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    };

    Solution s;
    ASSERT_EQ(s.maxAreaOfIsland(grid), 6);
}
