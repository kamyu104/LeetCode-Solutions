// Time:  O(nlogr), r = max(nums)
// Space: O(n)

// hash table
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        const auto& reverse = [](int n) {
            int result = 0;
            for (; n; n /= 10) {
                result = result * 10 + n % 10;
            }
            return result;
        };

        unordered_set<int> lookup(cbegin(nums), cend(nums));
        for (const auto& x : nums) {
            lookup.emplace(reverse(x));
        } 
        return size(lookup);
    }
};
