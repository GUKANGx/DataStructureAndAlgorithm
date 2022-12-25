#include "main.h"

using namespace std;
using namespace Utils::MyBinaryTree;

namespace {
    class Solution {
    public:
        TreeNode *sortedArrayToBST(vector<int> &nums)
        {
            if (nums.empty()) {
                return nullptr;
            }

            int left = 0, right = nums.size() - 1;
            int mid = left + (right - left) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            // {parent, {left1, right1, left2, right2}}
            std::queue<std::pair<TreeNode *, std::vector<int>>> q({{root, {left, mid - 1, mid + 1, right}}});
            while (!q.empty()) {
                auto &node = q.front();
                auto *parent = node.first;
                // left tree
                left = node.second[0];
                right = node.second[1];
                if (left <= right) {
                    mid = left + (right - left) / 2;
                    parent->left = new TreeNode(nums[mid]);
                    q.push({parent->left, {left, mid - 1, mid + 1, right}});
                }

                // right tree
                left = node.second[2];
                right = node.second[3];
                if (left <= right) {
                    mid = left + (right - left) / 2;
                    parent->right = new TreeNode(nums[mid]);
                    q.push({parent->right, {left, mid - 1, mid + 1, right}});
                }
                q.pop();
            }
            return root;
        }
    };
};

TEST(LeetCodeEnv, Q108_1)
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution solution;
    TreeNode *ans = solution.sortedArrayToBST(nums);
    vector<string> ansRootArr;
    SerializeBinaryTree(ans, ansRootArr);
    vector<string> exceptRootArr = {"0", "-10", "5", "null", "-3", "null", "9", "null", "null", "null", "null"};
    ASSERT_EQ(ansRootArr.size(), exceptRootArr.size());
    for (int i = 0; i < ansRootArr.size(); i++) {
        ASSERT_EQ(ansRootArr[i], exceptRootArr[i]);
    }
    FreeBinaryTree(ans);
}

