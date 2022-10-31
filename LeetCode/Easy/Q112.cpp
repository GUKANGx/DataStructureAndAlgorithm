#include "main.h"

using namespace std;
using namespace Utils::MyBinaryTree;

namespace {
    class Solution {
    public:
        bool hasPathSum(TreeNode* root, int targetSum)
        {
            if (root == nullptr) {
                return false;
            }
            queue<pair<TreeNode *, int>> q({ {root, root->val} });
            while (!q.empty()) {
                auto p = q.front();
                q.pop();
                if (p.second == targetSum && p.first->left == nullptr && p.first->right == nullptr) {
                    return true;
                }
                if (p.first->left != nullptr) {
                    q.push({p.first->left, p.second + p.first->left->val});
                }
                if (p.first->right != nullptr) {
                    q.push({p.first->right, p.second + p.first->right->val});
                }
            }
            return false;
        }
    };
};

TEST(leetcode, Q112_1)
{
    Solution solution;
    vector<string> rootArr = {"5", "4", "8", "11", "null", "13", "4", "7", "2", "null", "null", "null", "1"};
    auto *root = CreateBinaryTree(rootArr);
    int targetSum = 22;
    bool ans = solution.hasPathSum(root, targetSum);
    ASSERT_EQ(ans, true);
    FreeBinaryTree(root);
}