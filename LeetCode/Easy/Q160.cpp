#include "main.h"

using namespace std;
using namespace Utils::MyLinkedList;

namespace {
    class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
        {
            unordered_set<ListNode *>table;
            ListNode *tmpNode = headA;
            while (tmpNode != nullptr) {
                table.insert(tmpNode);
                tmpNode = tmpNode->next;
            }

            tmpNode = headB;
            while (tmpNode != nullptr) {
                if (table.find(tmpNode) != table.end()) {
                    return tmpNode;
                }
                tmpNode = tmpNode->next;
            }
            return nullptr;
        }
    };
};

TEST(LeetCodeEnv, Q160_1)
{
    Solution solution;
    vector<int> headAArr = {4, 1, 8, 4, 5};
    vector<int> headBArr = {5, 6, 1};
    ListNode *headA = CreateLinkedList(headAArr);
    ListNode *headB = CreateLinkedList(headBArr);
    ListNode *tailB = headB;
    while (tailB != nullptr && tailB->next != nullptr) {
        tailB = tailB->next;
    }
    ASSERT_NE(tailB, nullptr);
    ASSERT_EQ(tailB->next, nullptr);
    tailB->next = headA->next->next;
    ListNode *ans = solution.getIntersectionNode(headA, headB);
    ASSERT_EQ(ans, tailB->next);
    tailB->next = nullptr;
    FreeLinkedList(headA);
    FreeLinkedList(headB);
}