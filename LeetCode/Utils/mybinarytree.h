#ifndef DATASTRUCTUREANDALGORITHMUSINGCPP_MYBINARYTREE_H
#define DATASTRUCTUREANDALGORITHMUSINGCPP_MYBINARYTREE_H

namespace Utils::MyBinaryTree
{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    TreeNode *CreateBinaryTree(std::vector<std::string>& arr);
    void PrintBinaryTree(TreeNode *root);
    void SerializeBinaryTree(TreeNode *root, std::vector<std::string> &ret);
    void FreeBinaryTree(TreeNode *root);
};

#endif //DATASTRUCTUREANDALGORITHMUSINGCPP_MYBINARYTREE_H
