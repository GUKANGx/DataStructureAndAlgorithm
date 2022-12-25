#include "main.h"

using namespace std;
using namespace Utils::MyBinaryTree;

namespace {
    class Solution {
    public:
        vector<int> ans;
        void dfs(TreeNode* root)
        {
            if (root == nullptr) {
                return;
            }
            ans.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        }

        vector<int> preorderTraversal(TreeNode* root)
        {
            ans.clear();

//            dfs(root);

            stack<TreeNode *> s;
            s.push(root);
            while (!s.empty()) {
                auto *node = s.top();
                s.pop();
                if (node == nullptr) {
                    continue;
                }
                ans.push_back(node->val);
                s.push(node->right);
                s.push(node->left);
            }

            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q144_1)
{
    Solution solution;
    vector<string> headArr = {"1", "null", "2", "3"};
    TreeNode *root = CreateBinaryTree(headArr);
    vector<int> ans = solution.preorderTraversal(root);
    vector<int> exceptAns = {1, 2, 3};
    ASSERT_EQ(ans.size(), exceptAns.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i], exceptAns[i]);
    }
    FreeBinaryTree(root);
}