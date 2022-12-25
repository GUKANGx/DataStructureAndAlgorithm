#include "main.h"

using namespace std;
using namespace Utils::MyBinaryTree;

namespace {
    class Solution {
    public:
        bool isSymmetric(TreeNode *root)
        {
            std::list<TreeNode *> q({root});
            while (!q.empty()) {
                auto head = q.begin();
                auto tail = q.end();
                tail--;
                while (head != tail) {
                    if (((*head) == nullptr && (*tail) != nullptr) ||
                        ((*head) != nullptr && (*tail) == nullptr) ||
                        ((*head) != nullptr && (*tail) != nullptr && (*head)->val != (*tail)->val)) {
                        return false;
                    }
                    head++;
                    tail--;
                }

                size_t len = q.size();
                for (int i = 0; i < len; i++) {
                    auto *node = q.front();
                    q.pop_front();
                    if (node != nullptr) {
                        q.push_back(node->left);
                        q.push_back(node->right);
                    }
                }
            }
            return true;
        }
    };
};

TEST(LeetCodeEnv, Q101_1)
{
    vector<string>rootArr = {"1", "2", "2", "3", "4", "4", "3"};
    TreeNode *root = CreateBinaryTree(rootArr);
    Solution solution;
    ASSERT_TRUE(solution.isSymmetric(root));
    FreeBinaryTree(root);
}

