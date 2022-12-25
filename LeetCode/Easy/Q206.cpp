#include "main.h"

using namespace std;
using namespace Utils::MyLinkedList;

namespace {
    class Solution {
    public:
        ListNode* reverseList(ListNode* head)
        {
            if (head == nullptr) {
                return head;
            }
            ListNode *ans = new ListNode(head->val);
            while (head != nullptr && head->next != nullptr) {
                ListNode *p = new ListNode(head->next->val);
                p->next = ans;
                ans = p;
                head = head->next;
            }
            return ans;
        }
    };
};

TEST(LeetCodeEnv, Q206_1)
{
    Solution solution;
    vector<int> headArr = {1, 2, 3, 4};
    ListNode *head = CreateLinkedList(headArr);
    ListNode *ans = solution.reverseList(head);
    int i = headArr.size() - 1;
    while (ans != nullptr) {
        ASSERT_EQ(ans->val, headArr[i--]);
        ans = ans->next;
    }
    FreeLinkedList(head);
}