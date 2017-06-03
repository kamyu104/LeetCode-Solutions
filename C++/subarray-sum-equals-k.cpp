// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        auto result{0};
        auto accumulated_sum{0};
        unordered_map<int, int> lookup;
        ++lookup[0];
        for (const auto& num : nums) {
            accumulated_sum += num;
            result += lookup[accumulated_sum - k];
            ++lookup[accumulated_sum];
        }
        return result;
    }
};
