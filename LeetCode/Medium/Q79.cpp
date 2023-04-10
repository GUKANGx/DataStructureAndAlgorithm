#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        const vector<vector<int>> dirs = {
                {0, 1}, {1, 0}, {0, -1}, {-1, 0},
        };
        bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visit, int r, int c, string& word, int index)
        {
            if (board[r][c] != word[index]) {
                return false;
            }
            if (index == word.size() - 1) {
                return true;
            }

            visit[r][c] = true;
            bool res = false;
            int rows = board.size();
            int cols = board[0].size();
            for (const auto& dir: dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || visit[nr][nc]) {
                    continue;
                }
                if (dfs(board, visit, nr, nc, word, index + 1)) {
                    res = true;
                    break;
                }
            }
            visit[r][c] = false;
            return res;
        }

        bool exist(vector<vector<char>>& board, string word)
        {
            int rows = board.size();
            int cols = board[0].size();
            vector<vector<bool>> visit(rows, vector<bool>(cols));
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (dfs(board, visit, i, j, word, 0)) {
                        return true;
                    }
                }
            }
            return false;
        }
    };
};

TEST(LeetCodeEnv, Q79_1)
{
    Solution solution;
    vector<vector<char>> board = {
        {'a', 'a'},
    };
    string word = "aaa";
    bool ans = solution.exist(board, word);
    ASSERT_EQ(ans, false);
}

