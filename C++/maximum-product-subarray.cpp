// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = numeric_limits<int>::min();
        int curr_min = 1, curr_max = 1;
        for (const auto& num : nums) {
            tie(curr_min, curr_max) = pair(min({num, curr_min * num, curr_max * num}),
                                           max({num, curr_min * num, curr_max * num}));
            result = max(result, curr_max);
        }
        return result;
    }
};
