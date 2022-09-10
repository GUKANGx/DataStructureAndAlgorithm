#include "main.h"

using namespace std;

namespace {
    class KthLargest
    {
    public:
        KthLargest(int k, vector<int>& nums)
        {
            this->k = k;
            for (const auto & n : nums) {
                this->add(n);
            }
        }

        int add(int val)
        {
            pq.push(val);
            if (pq.size() > k) {
                pq.pop();
            }
            return pq.top();
        }
    private:
        priority_queue<int, vector<int>, greater<>> pq;
        int k = 0;
    };
};

TEST(leetcode, Q703_1)
{
    vector<int> nums {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    ASSERT_EQ(kthLargest.add(3), 4);
    ASSERT_EQ(kthLargest.add(5), 5);
    ASSERT_EQ(kthLargest.add(10), 5);
    ASSERT_EQ(kthLargest.add(9), 8);
    ASSERT_EQ(kthLargest.add(4), 8);
}

