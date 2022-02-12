#include "main.h"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) {
            return s;
        }

        int sLen = s.size();
        int interval = 2 * numRows - 2;

        vector<vector<char>> table;

        vector<char> tmp(numRows);
        for (int i = 0; i < sLen; i++) {
            int mod = i % interval;
            if (mod < numRows) {
                tmp[mod] = s[i];
            } else {
                int index = numRows - (mod - numRows) - 2;
                tmp[index] = s[i];
            }
            if (mod >= numRows - 1 || i == sLen - 1) {
                table.push_back(tmp);
                tmp = vector<char>(numRows);
            }
        }

        string ans = "";
        int rows = table.size();
        int cols = table[0].size();
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                if (table[j][i] == 0) {
                    continue;
                }
                ans += table[j][i];
            }
        }

        return ans;
    }
};

void Q6Main(void)
{
    cout << "Q6: " << endl;

    string str = "PAYPALISHIRING";
    int numRows = 3;
    Solution s;
    cout << s.convert(str, numRows) << endl;
    cout << "Done" << endl;
}

