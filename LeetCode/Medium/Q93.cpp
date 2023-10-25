#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        bool IsValid(std::string ipSection) const
        {
            if (ipSection.size() > 3 || ipSection.empty()) {
                return false;
            }

            if (ipSection.size() > 1 && ipSection[0] == '0') {
                return false;
            }

            if (ipSection.size() >= 3 && ipSection > "255") {
                return false;
            }
            return true;
        }

        vector<string> restoreIpAddresses(string s)
        {
            int sLen = s.size();
            if (sLen < 3) {
                return {};
            }

            using NodeType = std::vector<std::pair<int, int>>;
            std::queue<NodeType> q;
            std::string tmp;
            for (int i = 0; i < 3; i++) {
                tmp += s[i];
                if (IsValid(tmp)) {
                    NodeType node {{0, tmp.size()}};
                    q.push(node);
                }
            }

            std::vector<std::string> ans;
            while (!q.empty()) {
                NodeType node = q.front();
                q.pop();
                int startIndex = node.back().first + node.back().second;
                if (node.size() >= 4) {
                    if (startIndex == sLen) {
                        tmp = "";
                        int nodeLen = node.size();
                        for (int j = 0; j < nodeLen; j++) {
                            tmp += s.substr(node[j].first, node[j].second);
                            if (j != nodeLen - 1) {
                                tmp += ".";
                            }
                        }
                        ans.push_back(tmp);
                    }
                    continue;
                }
                tmp = "";
                for (int i = startIndex; i < sLen && i < startIndex + 3; i++) {
                    tmp += s[i];
                    if (!IsValid(tmp)) {
                        continue;
                    }
                    NodeType nodeNew = node;
                    nodeNew.push_back({startIndex, tmp.size()});
                    q.push(nodeNew);
                }
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q93_1)
{
    Solution solution;
    string s = "25525511135";
    std::unordered_set<string> ansExpect = {"255.255.11.135","255.255.111.35"};
    auto ans = solution.restoreIpAddresses(s);
    ASSERT_EQ(ans.size(), ansExpect.size());
    for (int i = 0; i < ans.size(); i++) {
        auto it = ansExpect.find(ans[i]);
        ASSERT_EQ(it != ansExpect.end(), true);
    }
}

