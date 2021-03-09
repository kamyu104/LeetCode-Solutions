// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int64_t total = accumulate(cbegin(nums), cend(nums), 0LL);
        return (abs(total - goal) + (limit - 1)) / limit;
    }
};
