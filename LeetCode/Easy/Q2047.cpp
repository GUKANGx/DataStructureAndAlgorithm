#include "main.h"

using namespace std;

namespace {
    class Solution
    {
    public:
        bool IsHyphen(char ch)
        {
            return ch == '-';
        }

        bool IsSpace(char ch)
        {
            return ch == ' ';
        }

        bool IsPunctuation(char ch)
        {
            return ch == '!' || ch == '.' || ch == ',';
        }

        bool checkHelper1(char ch)
        {
            if (islower(ch) || IsHyphen(ch) || IsPunctuation(ch)) {
                return true;
            }
            return false;
        }

        int countValidWords(string sentence)
        {
            size_t len = sentence.size();
            int ans = 0;
            bool isValid = true, hasHyphen = false, hasSymbol = false;
            int countSymbol = 0;

            for (size_t i = 0; i < len + 1; i++) {
                char ch = sentence[i];
                if (IsSpace(ch) || i == len) {
                    ans += (int)(isValid && (countSymbol > 0));
                    isValid = true;
                    hasHyphen = false;
                    hasSymbol = false;
                    countSymbol = 0;
                    continue;
                }
                if (!isValid) {
                    continue;
                }
                countSymbol++;
                isValid = checkHelper1(ch);
                if (IsHyphen(ch)) {
                    if (hasHyphen || i == 0 || !islower(sentence[i - 1]) ||
                        i == len - 1 || !islower(sentence[i + 1])) {
                        isValid = false;
                    }
                    hasHyphen = true;
                }
                if (IsPunctuation(ch)) {
                    if (hasSymbol || (i != len - 1 && !IsSpace(sentence[i + 1]))) {
                        isValid = false;
                    }
                    hasSymbol = true;
                }
            }
            return ans;
        }
    };
};

TEST(leetcode, Q2047_1)
{
    string sentence = "cat and  dog";
    Solution solution;
    ASSERT_EQ(solution.countValidWords(sentence), 3);
}

