#include "main.h"

using namespace std;
using namespace Utils::MyLinkedList;

namespace {
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

TEST(LeetCodeEnv, Q21_1)
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

