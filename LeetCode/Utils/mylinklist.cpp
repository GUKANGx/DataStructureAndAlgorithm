#include <iostream>
#include <vector>

#include "mylinklist.h"

Utils::MyLinkedList::ListNode* Utils::MyLinkedList::CreateLinkedList(std::vector<int> &arr)
{
    if (arr.empty()) {
        return nullptr;
    }
    ListNode *head = new ListNode(arr[0], nullptr);
    ListNode *tmp = head;
    for (int i = 1; i < arr.size(); i++) {
        tmp->next = new ListNode(arr[i], nullptr);
        tmp = tmp->next;
    }
    return head;
}


void Utils::MyLinkedList::PrintLinkedList(ListNode *head)
{
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

void Utils::MyLinkedList::FreeLinkedList(ListNode *head)
{
    while (head != nullptr) {
        ListNode *p = head;
        head = head->next;
        free(p);
        p = nullptr;
    }
}

