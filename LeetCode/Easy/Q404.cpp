#include "main.h"

using namespace std;
using namespace Utils::MyBinaryTree;

namespace {
    class Solution {
    public:
        int sumOfLeftLeaves(TreeNode* root)
        {
            queue<TreeNode *> q {{root}};
            int ans = 0;
            while (!q.empty()) {
                auto *node = q.front();
                q.pop();
                if (node == nullptr) {
                    continue;
                }
                if (node->left != nullptr) {
                    if (node->left->left == nullptr && node->left->right == nullptr) {
                        ans += node->left->val;
                    }
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q404_1)
{
    Solution solution;
    vector<string> headArr = {"3", "9", "20", "null", "null", "15", "7"};
    auto root = CreateBinaryTree(headArr);
    int ans = solution.sumOfLeftLeaves(root);
    ASSERT_EQ(ans, 24);
    FreeBinaryTree(root);
}