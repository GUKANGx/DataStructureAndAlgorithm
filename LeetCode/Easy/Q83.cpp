#include "main.h"

using namespace std;
using namespace Utils::MyLinkedList;

namespace {
    class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head)
        {
            ListNode *tmp = head;
            while (tmp != nullptr && tmp->next != nullptr) {
                if (tmp->val == tmp->next->val) {
                    ListNode *p = tmp->next;
                    tmp->next = tmp->next->next;
                    delete p;
                } else {
                    tmp = tmp->next;
                }
            }
            return head;
        }
    };
};

TEST(LeetCodeEnv, Q83_1)
{
    vector<int> arr {1, 1, 2};
    ListNode *head = CreateLinkedList(arr);
    Solution solution;
    auto ans = solution.deleteDuplicates(head);
    vector<int> exceptArr {1, 2};
    ListNode *exceptHead = CreateLinkedList(exceptArr);
    while (exceptHead != nullptr) {
        ASSERT_NE(ans, nullptr);
        ASSERT_EQ(exceptHead->val, ans->val);
        exceptHead = exceptHead->next;
        ans = ans->next;
    }
}

