#include "main.h"

using namespace std;
using namespace Utils::MyBinaryTree;

namespace {
    class Solution {
    public:
        int maxDepth(TreeNode* root)
        {
            if (root == nullptr) {
                return 0;
            }
            std::queue<std::pair<TreeNode *, int>> q({{root, 1}});
            int depth = 0;
            while (!q.empty()) {
                auto &node = q.front();
                depth = node.second > depth ? node.second : depth;
                if (node.first->left != nullptr) {
                    q.push({node.first->left, node.second + 1});
                }
                if (node.first->right != nullptr) {
                    q.push({node.first->right, node.second + 1});
                }
                q.pop();
            }
            return depth;
        }
    };
};

TEST(leetcode, Q104_1)
{
    vector<string>rootArr = {"3", "9", "20", "null", "null", "15", "7"};
    TreeNode *root = CreateBinaryTree(rootArr);
    Solution solution;
    ASSERT_EQ(solution.maxDepth(root), 3);
    FreeBinaryTree(root);
}

