#include "main.h"

using namespace std;
using namespace Utils::MyBinaryTree;

namespace {
    class Solution {
    public:
        std::priority_queue<int> priQ;
        void dfs(TreeNode* node, int k)
        {
            if (node == nullptr) {
                return;
            }
            priQ.push(node->val);
            if (priQ.size() > k) {
                priQ.pop();
            }
            dfs(node->left, k);
            dfs(node->right, k);
        }

        int kthSmallest(TreeNode* root, int k)
        {
            priQ = std::priority_queue<int>();
            dfs(root, k);
            return priQ.top();
        }
    };
};

TEST(LeetCodeEnv, Q230_1)
{
    Solution solution;
    std::vector<std::string> arr = {"3", "1", "4", "null", "2"};
    TreeNode* treeNode = CreateBinaryTree(arr);
    PrintBinaryTree(treeNode);
    FreeBinaryTree(treeNode);
}

