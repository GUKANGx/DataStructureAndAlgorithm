#include "main.h"

using namespace std;
using namespace Utils::MyLinkedList;

namespace {
    class Solution {
    public:
        ListNode* removeElements(ListNode* head, int val)
        {
            ListNode *ans = new ListNode(-1);
            ans->next = head;
            ListNode *tmp = ans;
            while (tmp != nullptr) {
                if (tmp->next != nullptr && tmp->next->val == val) {
                    ListNode *p = tmp->next;
                    tmp->next = tmp->next->next;
                    delete p;
                } else {
                    tmp = tmp->next;
                }
            }
            ListNode *p = ans;
            ans = ans->next;
            delete p;
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q203_1)
{
    Solution solution;
    vector<int> headArr = {1,2,6,3,4,5,6};
    ListNode *head = CreateLinkedList(headArr);
    ListNode *ans = solution.removeElements(head, 6);
    while (ans != nullptr) {
        ASSERT_NE(ans->val, 6);
        ans = ans->next;
    }
    FreeLinkedList(head);
}