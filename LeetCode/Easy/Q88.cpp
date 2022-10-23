#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
        {
            size_t j = nums1.size() - 1;
            for (int i = m - 1; i >= 0; i--) {
                nums1[j--] = nums1[i];
            }

            int k = 0;
            int i = 0;
            size_t len = nums1.size();
            j++;
            while (k < n && j < len) {
                if (nums1[j] < nums2[k]) {
                    nums1[i++] = nums1[j++];
                } else {
                    nums1[i++] = nums2[k++];
                }
            }
            while (k < n) {
                nums1[i++] = nums2[k++];
            }
            while (j < len) {
                nums1[i++] = nums1[j++];
            }
        }
    };
};

TEST(leetcode, Q88_1)
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    Solution solution;
    solution.merge(nums1, m, nums2, n);
    vector<int> exceptAns = {1, 2, 2, 3, 5, 6};
    for (int i = 0; i < exceptAns.size(); i++) {
        ASSERT_EQ(nums1[i], exceptAns[i]);
    }
}

