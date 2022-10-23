#include <vector>
#include <iostream>
#include <sstream>
#include <queue>

#include "mybinarytree.h"

Utils::MyBinaryTree::TreeNode *Utils::MyBinaryTree::CreateBinaryTree(std::vector<std::string> &arr)
{
    if (arr.empty() ||  arr.front() == "null") {
        return nullptr;
    }
    TreeNode *root = new TreeNode(std::stoi(arr[0]));
    std::queue<TreeNode *> q ({root});
    size_t i = 1, len = arr.size();
    while (i < len && !q.empty()) {
        TreeNode *parent = q.front();
        q.pop();
        if (i < len && arr[i] != "null") {
            parent->left = new TreeNode(std::stoi(arr[i]));
            q.push(parent->left);
        }
        i++;
        if (i < len && arr[i] != "null") {
            parent->right = new TreeNode(std::stoi(arr[i]));
            q.push(parent->right);
        }
        i++;
    }
    return root;
}

void Utils::MyBinaryTree::PrintBinaryTree(TreeNode *root)
{
    if (root == nullptr) {
        return;
    }
    std::queue<TreeNode *> q ({root});
    while (!q.empty()) {
        TreeNode *parent = q.front();
        q.pop();
        if (parent == nullptr) {
            std::cout << "null" << " ";
            continue;
        } else {
            std::cout << parent->val << " ";
        }
        q.push(parent->left);
        q.push(parent->right);
    }
    std::cout << std::endl;
}

void Utils::MyBinaryTree::SerializeBinaryTree(TreeNode *root, std::vector<std::string> &ret)
{
    if (root == nullptr) {
        return;
    }
    std::queue<TreeNode *> q ({root});
    while (!q.empty()) {
        TreeNode *parent = q.front();
        q.pop();
        if (parent == nullptr) {
            ret.emplace_back("null");
            continue;
        } else {
            std::stringstream ss;
            ss << parent->val;
            ret.emplace_back(ss.str());
        }
        q.push(parent->left);
        q.push(parent->right);
    }
}

void Utils::MyBinaryTree::FreeBinaryTree(TreeNode *root)
{
    if (root->left != nullptr) {
        FreeBinaryTree(root->left);
    }
    if (root->right != nullptr) {
        FreeBinaryTree(root->right);
    }
    delete root;
    root = nullptr;
}
