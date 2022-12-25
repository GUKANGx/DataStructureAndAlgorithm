#include "main.h"

using namespace std;
using namespace Utils::MyLinkedList;

namespace {
    class Solution {
    public:
        bool isPalindrome(ListNode* head)
        {
            vector<int> arr;
            while (head != nullptr) {
                arr.push_back(head->val);
                head = head->next;
            }
            if (arr.empty()) {
                return false;
            }
            int i = 0, j = arr.size() - 1;
            while (i < j) {
                if (arr[i++] != arr[j--]) {
                    return false;
                }
            }
            return true;
        }
    };
};

TEST(LeetCodeEnv, Q234_1)
{
    Solution solution;
    vector<int> headArr = {1, 2, 2, 1};
    ListNode *head = CreateLinkedList(headArr);
    auto ans = solution.isPalindrome(head);
    ASSERT_TRUE(ans);
    FreeLinkedList(head);
}