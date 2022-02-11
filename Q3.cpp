#include "main.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.size();
        int ans = 0;
        unordered_map<char, int> table;
        int left = 0, right = 0;
        while (right < len) {
            auto it = table.find(s[right]);
            if (it == table.end() || it->second == 0) {
                table[s[right++]]++;
                ans = max(ans, right - left);
            } else {
                table[s[left++]]--;
            }
        }
        return ans;
    }
};

void Q3Main(void)
{
    cout << "Q3: " << endl;

    string str = "abcabcbb";
    Solution s;
    cout << s.lengthOfLongestSubstring(str) << endl;

    cout << "Done" << endl;
}

