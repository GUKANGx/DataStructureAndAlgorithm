#include "main.h"

using namespace std;
using namespace Utils::MyBinaryTree;

namespace {
    class Solution {
    public:
        vector<int> ans;

        vector<int> inorderTraversal(TreeNode* root)
        {
            ans.clear();
//            inorderTraversalR(root);
            inorderTraversalI(root);
            return ans;
        }

        void inorderTraversalI(TreeNode* root)
        {
            stack<TreeNode *>st;
            while (!st.empty() || root != nullptr) {
                while (root != nullptr) {
                    st.push(root);
                    root = root->left;
                }
                root = st.top();
                st.pop();
                ans.emplace_back(root->val);
                root = root->right;
            }
        }

        void inorderTraversalR(TreeNode* root)
        {
            if (root == nullptr) {
                return;
            }
            if (root->left != nullptr) {
                inorderTraversalR(root->left);
            }
            ans.emplace_back(root->val);
            if (root->right != nullptr) {
                inorderTraversalR(root->right);
            }
        }
    };
};

TEST(LeetCodeEnv, Q94_1)
{
    vector<string> rootArr = {"1", "null", "2", "3"};
    TreeNode *root = CreateBinaryTree(rootArr);
    Solution solution;
    vector<int> ans = solution.inorderTraversal(root);
    const vector<int> expectAns = {1, 3, 2};
    ASSERT_EQ(ans.size(), expectAns.size());
    for (int i = 0; i < ans.size(); i++) {
        ASSERT_EQ(ans[i], expectAns[i]);
    }
}

