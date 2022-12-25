#include "main.h"

using namespace std;
using namespace Utils::MyLinkedList;

namespace {
    class Solution {
    public:
        bool wordPatternHelper(vector<string>& patternList, vector<string>& sList)
        {
            unordered_map<string, string> table;
            if (patternList.size() != sList.size()) {
                return false;
            }
            int len = patternList.size();
            for (int i = 0; i < len; i++) {
                if (table.find(patternList[i]) == table.end()) {
                    table[patternList[i]] = sList[i];
                } else if (table[patternList[i]] != sList[i]) {
                    return false;
                }
            }
            return true;
        }

        bool wordPattern(string pattern, string s)
        {
            vector<string> patternList;
            int len = pattern.size();
            for (int i = 0; i < len; i++) {
                patternList.push_back(pattern.substr(i, 1));
            }
            vector<string> sList {""};
            for (const auto & c : s) {
                if (c == ' ') {
                    sList.emplace_back("");
                } else {
                    sList.back() += c;
                }
            }
            return wordPatternHelper(patternList, sList) && wordPatternHelper(sList, patternList);
        }
    };
};

TEST(LeetCodeEnv, Q290_1)
{
    Solution solution;
    auto ans = solution.wordPattern("abba", "dog cat cat dog");
    ASSERT_TRUE(ans);
}