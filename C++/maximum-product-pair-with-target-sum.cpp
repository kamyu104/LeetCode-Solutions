// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int mx = numeric_limits<int>::min();
        unordered_map<int, int> lookup;
        for (const auto& [i, x] : ranges::views::enumerate(nums)) {
            if (lookup.count(target - x) && x != target - x && x * (target - x) > mx) {
                mx = x * (target - x);
                result = {static_cast<int>(i), lookup[target - x]};
                if (x < target - x) {
                    swap(result[0], result[1]);
                }
            }
            lookup[x] = i;
        }
        return result;
    }
};
