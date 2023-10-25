#include "main.h"

using namespace std;

namespace {
    class Solution {
    public:
        int GetID(uint64_t x, uint64_t t)
        {
            if (x >= 0) {
                return x / (t + 1);
            }
            return (x + 1) / (t + 1) - 1;
        }

        bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff)
        {
            std::unordered_map<int, int> idMap;
            for (int i = 0; i < nums.size(); i++) {
                int index = i - (indexDiff + 1);
                if (index >= 0) {
                    int tmpId = GetID(nums[index], valueDiff);
                    auto it = idMap.find(tmpId);
                    if (it != idMap.end()) {
                        idMap.erase(it);
                    }
                }

                uint64_t x = nums[i];
                int id = GetID(x, valueDiff);
                auto it = idMap.find(id);
                if (it != idMap.end()) {
                    return true;
                }

                int preId = id - 1;
                it = idMap.find(preId);
                if (it != idMap.end() && labs((uint64_t)(it->second) - nums[i]) <= valueDiff) {
                    return true;
                }

                int nextId = id + 1;
                it = idMap.find(nextId);
                if (it != idMap.end() && labs((uint64_t)(it->second) - nums[i]) <= valueDiff) {
                    return true;
                }

                idMap.insert({id, nums[i]});
            }
            return false;
        }
    };
};

TEST(LeetCodeEnv, Q220_1)
{
    Solution solution;
    std::vector<int> nums = {1, 5, 9, 1, 5, 9};
    int indexDiff = 2;
    int valueDiff = 3;
    auto ans = solution.containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);
    ASSERT_EQ(ans, false);
}

