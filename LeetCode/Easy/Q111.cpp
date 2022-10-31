#include "main.h"

using namespace std;
using namespace Utils::MyBinaryTree;

namespace {
    class Solution {
    public:
        int minDepth(TreeNode* root)
        {
            if (root == nullptr) {
                return 0;
            }
            queue<pair<TreeNode *, int>> q({ {root, 1} });
            while (!q.empty()) {
                auto p = q.front();
                q.pop();
                if (p.first->left == nullptr && p.first->right == nullptr) {
                    return p.second;
                }
                if (p.first->left != nullptr) {
                    q.push({p.first->left, p.second + 1});
                }
                if (p.first->right != nullptr) {
                    q.push({p.first->right, p.second + 1});
                }
            }
            return 0;
        }
    };
};

TEST(leetcode, Q111_1)
{
    Solution solution;
    vector<string> rootArr = {"3", "9", "20", "null", "null", "15", "7"};
    auto *root = CreateBinaryTree(rootArr);
    int ans = solution.minDepth(root);
    ASSERT_EQ(ans, 2);
    FreeBinaryTree(root);
}