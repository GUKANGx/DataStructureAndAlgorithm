#include "main.h"

using namespace std;
using namespace Utils::MyLinkedList;

namespace {
    class Solution {
    public:
        bool hasCycle(ListNode *head)
        {
            unordered_set<ListNode *> table;
            while (head != nullptr) {
                if (table.find(head) != table.end()) {
                    return true;
                }
                table.insert(head);
                head = head->next;
            }
            return false;
        }
    };
};

TEST(LeetCodeEnv, Q141_1)
{
    Solution solution;
    vector<int> headArr = {3, 2, 0, -4};
    ListNode *head = CreateLinkedList(headArr);
    ListNode *tail = head;
    while (tail != nullptr && tail->next != nullptr) {
        tail = tail->next;
    }
    ASSERT_NE(tail, nullptr);
    tail->next = head;
    bool ans = solution.hasCycle(head);
    ASSERT_EQ(ans, true);
    tail->next = nullptr;
    FreeLinkedList(head);
}