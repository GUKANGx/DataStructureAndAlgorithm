#include "main.h"

using namespace std;
using namespace Utils::MyBinaryTree;

namespace {
    class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q)
        {
            std::queue<TreeNode *> pq({p});
            std::queue<TreeNode *> qq({q});
            while (!pq.empty() && !qq.empty()) {
                auto *pNode = pq.front();
                pq.pop();
                auto *qNode = qq.front();
                qq.pop();
                if ((pNode == nullptr && qNode != nullptr) ||
                    (pNode != nullptr && qNode == nullptr) ||
                    (pNode != nullptr && qNode != nullptr && pNode->val != qNode->val)) {
                    return false;
                }
                if (pNode != nullptr) {
                    pq.push(pNode->left);
                    pq.push(pNode->right);
                }
                if (qNode != nullptr) {
                    qq.push(qNode->left);
                    qq.push(qNode->right);
                }
            }
            return pq.empty() && qq.empty();
        }
    };
};

TEST(leetcode, Q100_1)
{
    vector<string>pArr = {"1", "2", "3"};
    TreeNode *pRoot = CreateBinaryTree(pArr);
    vector<string>qArr = {"1", "2", "3"};
    TreeNode *qRoot = CreateBinaryTree(qArr);
    Solution solution;
    ASSERT_TRUE(solution.isSameTree(pRoot, qRoot));
    FreeBinaryTree(pRoot);
    FreeBinaryTree(qRoot);
}

