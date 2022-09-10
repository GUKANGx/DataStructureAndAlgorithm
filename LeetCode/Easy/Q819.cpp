#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        string mostCommonWord(string paragraph, vector<string>& banned)
        {
            unordered_set<string> bannedMap(banned.begin(), banned.end());
            unordered_map<string, int> countMap;

            int len = paragraph.size();
            string ans, tmpStr;
            int maxFreq = 0;
            for (int i = 0; i < len + 1; i++) {
                if (i == len || !isalpha(paragraph[i])) {
                    if (!tmpStr.empty() && bannedMap.find(tmpStr) == bannedMap.end()) {
                        if (countMap.find(tmpStr) == countMap.end()) {
                            countMap[tmpStr] = 1;
                        } else {
                            countMap[tmpStr]++;
                        }
                        if (countMap[tmpStr] > maxFreq) {
                            ans = tmpStr;
                            maxFreq = countMap[tmpStr];
                        }
                    }
                    tmpStr.clear();
                    continue;
                }
                tmpStr += tolower(paragraph[i]);
            }
            return std::move(ans);
        }

    };
};

TEST(leetcode, Q819_1)
{
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};
    Solution solution;
    string ans = solution.mostCommonWord(paragraph, banned);
    ASSERT_EQ(ans, "ball");
}

