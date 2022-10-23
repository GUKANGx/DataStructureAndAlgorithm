#ifndef DATASTRUCTUREANDALGORITHMUSINGCPP_MYLINKLIST_H
#define DATASTRUCTUREANDALGORITHMUSINGCPP_MYLINKLIST_H

#include <vector>
#include <iostream>

namespace Utils::MyLinkedList
{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* CreateLinkedList(std::vector<int> &arr);
    void PrintLinkedList(ListNode *head);
    void FreeLinkedList(ListNode* head);
};

#endif //DATASTRUCTUREANDALGORITHMUSINGCPP_MYLINKLIST_H
