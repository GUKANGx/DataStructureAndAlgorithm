#include "main.h"

using namespace std;

namespace {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* CreateLinkedList(vector<int> &arr)
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

    void PrintLinkedList(ListNode *head)
    {
        while (head != nullptr) {
            cout << head->val;
            if (head->next != nullptr) {
                cout << " -> ";
            }
            head = head->next;
        }
        cout << endl;
    }

    void FreeLinkedList(ListNode* head)
    {
        while (head != nullptr) {
            ListNode *p = head;
            head = head->next;
            free(p);
            p = nullptr;
        }
    }

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

TEST(leetcode, Q83_1)
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

