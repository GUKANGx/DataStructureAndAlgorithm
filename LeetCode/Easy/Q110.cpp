#include "main.h"

using namespace std;
using namespace Utils::MyBinaryTree;

namespace {
    class Solution {
    public:
        unordered_map<TreeNode *, int> depthMap;
        int treeDepth(TreeNode *root)
        {
            if (root == nullptr) {
                return 0;
            }
            int leftDepth = treeDepth(root->left) + 1;
            int rightDepth = treeDepth(root->right) + 1;
            return max(leftDepth, rightDepth);;
        }

        bool isBalancedHelper(TreeNode* root)
        {
            if (root == nullptr) {
                return true;
            }

            if (!isBalancedHelper(root->left)) {
                return false;
            }
            if (!isBalancedHelper(root->right)) {
                return false;
            }

            int leftDepth, rightDepth;
            if (root->left != nullptr && depthMap.find(root->left) != depthMap.end()) {
                leftDepth = depthMap[root->left];
            } else {
                leftDepth = treeDepth(root->left);
            }
            if (root->right != nullptr && depthMap.find(root->right) != depthMap.end()) {
                rightDepth = depthMap[root->right];
            } else {
                rightDepth = treeDepth(root->right);
            }
            int currDepth = max(leftDepth + 1, rightDepth + 1);
            depthMap[root] = currDepth;
            if (abs(rightDepth - leftDepth) > 1) {
                return false;
            }
            return true;
        }

        bool isBalanced(TreeNode* root)
        {
            if (root == nullptr) {
                return true;
            }
            depthMap.clear();
            return isBalancedHelper(root);
        }
    };
};

TEST(leetcode, Q110_1)
{
    Solution solution;
    vector<string> rootArr = {"3", "9", "20", "null", "null", "15", "7"};
    auto *root = CreateBinaryTree(rootArr);
    bool ans = solution.isBalanced(root);
    ASSERT_EQ(ans, true);
    FreeBinaryTree(root);
}