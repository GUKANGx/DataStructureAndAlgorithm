#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        const vector<vector<int>> dir = {{1,  0},
                                         {-1, 0},
                                         {0,  1},
                                         {0,  -1}};

        void dfs1(vector<vector<int>> &grid, int currRow, int currCol, int fill) {
            int maxRow = grid.size();
            int maxCol = grid[0].size();

            for (int i = 0; i < dir.size(); i++) {
                int nextRow = currRow + dir[i][0];
                int nextCol = currCol + dir[i][1];
                if (nextRow < 0 || nextRow >= maxRow || nextCol < 0 || nextCol >= maxCol ||
                    grid[nextRow][nextCol] != 1) {
                    continue;
                }
                grid[nextRow][nextCol] = fill;
                dfs1(grid, nextRow, nextCol, fill);
            }
        }

        int ans = 0;
        int pre = -1;
        bool flag = true;

        void dfs2(const vector<vector<int>> &grid1, vector<vector<int>> &grid2, int currRow, int currCol) {
            int maxRow = grid2.size();
            int maxCol = grid2[0].size();

            for (int i = 0; i < dir.size(); i++) {
                int nextRow = currRow + dir[i][0];
                int nextCol = currCol + dir[i][1];
                if (nextRow < 0 || nextRow >= maxRow || nextCol < 0 || nextCol >= maxCol ||
                    grid2[nextRow][nextCol] != 1) {
                    continue;
                }
                grid2[nextRow][nextCol] = 2;
                if (flag && grid1[nextRow][nextCol] != pre) {
                    flag = false;
                }
                dfs2(grid1, grid2, nextRow, nextCol);
            }
        }

        int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
            int maxRow = grid1.size();
            int maxCol = grid1[0].size();

            int fill = 2;
            for (int i = 0; i < maxRow; i++) {
                for (int j = 0; j < maxCol; j++) {
                    if (grid1[i][j] != 1) {
                        continue;
                    }
                    grid1[i][j] = fill;
                    dfs1(grid1, i, j, fill);
                    fill++;
                }
            }

            ans = 0;
            for (int i = 0; i < maxRow; i++) {
                for (int j = 0; j < maxCol; j++) {
                    if (grid2[i][j] != 1) {
                        continue;
                    }
                    grid2[i][j] = 2;
                    pre = grid1[i][j];
                    flag = pre >= 2;
                    dfs2(grid1, grid2, i, j);
                    if (flag) {
                        ans++;
                    }
                }
            }

            return ans;
        }
    };
};

TEST(leetcode, Q1905_1)
{
    vector<vector<int>> grid1 = {
            { 1, 1, 1, 0, 0 },
            { 0, 1, 1, 1, 1 },
            { 0, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 1, 1, 0, 1, 1 },
    };

    vector<vector<int>> grid2 = {
            { 1, 1, 1, 0, 0 },
            { 0, 0, 1, 1, 1 },
            { 0, 1, 0, 0, 0 },
            { 1, 0, 1, 1, 0 },
            { 0, 1, 0, 1, 0 },
    };

    Solution s;
    ASSERT_EQ(s.countSubIslands(grid1, grid2), 3);
}

