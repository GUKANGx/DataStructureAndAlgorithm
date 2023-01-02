#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        unordered_map<char, int> lineTable = {
                // "qwertyuiop"
                {'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1},
                {'y', 1}, {'u', 1}, {'i', 1}, {'o', 1}, {'p', 1},
                // "asdfghjkl"
                {'a', 2}, {'s', 2}, {'d', 2}, {'f', 2}, {'g', 2},
                {'h', 2}, {'j', 2}, {'k', 2}, {'l', 2},
                // "zxcvbnm"
                {'z', 3}, {'x', 3}, {'c', 3}, {'v', 3}, {'b', 3},
                {'n', 3}, {'m', 3},
        };

        vector<string> findWords(vector<string>& words)
        {
            vector<string> ans;
            for (const auto &word : words) {
                int currLine = -1;
                for (const auto &c : word) {
                    auto it = lineTable[tolower(c)];
                    if (currLine != -1 && it != currLine) {
                        currLine = -1;
                        break;
                    }
                    currLine = it;
                }
                if (currLine != -1) {
                    ans.emplace_back(word);
                }
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q500_1)
{
    Solution solution;
    vector<string> words = {"Hello","Alaska","Dad","Peace"};
    vector<string> ans = solution.findWords(words);
    vector<string> exceptAns = {"Alaska","Dad"};
    ASSERT_EQ(ans.size(), exceptAns.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i], exceptAns[i]);
    }
}