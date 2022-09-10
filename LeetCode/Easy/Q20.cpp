#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        bool isValid(string s)
        {
            unordered_map<char, char> matchMap = {
                    {'(', ')'},
                    {'{', '}'},
                    {'[', ']'},
            };
            stack<char> ss;
            for (const auto &ch : s) {
                if (ch == ')' || ch == '}' || ch == ']') {
                    if (ss.empty()) {
                        return false;
                    }
                    char tmp = ss.top();
                    ss.pop();
                    if (matchMap[tmp] != ch) {
                        return false;
                    }
                    continue;
                }
                ss.push(ch);
            }
            return ss.empty();
        }
    };
};

TEST(leetcode, Q20_1)
{
    string s = "()[]{}";
    Solution solution;
    ASSERT_EQ(solution.isValid(s), true);
}

