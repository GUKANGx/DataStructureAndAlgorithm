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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
        {
            ListNode *ans = nullptr;
            ListNode *ansTmp = nullptr;
            while (list1 != nullptr || list2 != nullptr) {
                ListNode** tmp = &list1;
                if (*tmp == nullptr || (list2 != nullptr && list2->val < (*tmp)->val)) {
                    tmp = &list2;
                }
                if (ans == nullptr) {
                    ans = new ListNode((*tmp)->val, nullptr);
                    ansTmp = ans;
                } else {
                    ansTmp->next = new ListNode((*tmp)->val, nullptr);
                    ansTmp = ansTmp->next;
                }
                *tmp = (*tmp)->next;
            }
            return ans;
        }
    };
};

TEST(leetcode, Q21_1)
{
    vector<int> arr1 = {1, 2, 4};
    vector<int> arr2 = {1, 3, 4};
    ListNode *list1 = CreateLinkedList(arr1);
    ListNode *list2 = CreateLinkedList(arr2);
    Solution solution;
    ListNode *ans = solution.mergeTwoLists(list1, list2);

    vector<int> exceptArr = {1, 1, 2, 3, 4, 4};
    ListNode *exceptList = CreateLinkedList(exceptArr);
    while (exceptList != nullptr) {
        ASSERT_NE(ans, nullptr);
        ASSERT_EQ(exceptList->val, ans->val);
        exceptList = exceptList->next;
        ans = ans->next;
    }
}

