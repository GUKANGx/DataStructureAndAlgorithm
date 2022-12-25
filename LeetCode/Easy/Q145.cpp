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
            dfs(root->left);
            dfs(root->right);
            ans.push_back(root->val);
        }

        vector<int> postorderTraversal(TreeNode* root)
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
                s.push(node->left);
                s.push(node->right);
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q145_1)
{
    Solution solution;
    vector<string> headArr = {"1", "null", "2", "3"};
    TreeNode *root = CreateBinaryTree(headArr);
    vector<int> ans = solution.postorderTraversal(root);
    vector<int> exceptAns = {3, 2, 1};
    ASSERT_EQ(ans.size(), exceptAns.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i], exceptAns[i]);
    }
    FreeBinaryTree(root);
}