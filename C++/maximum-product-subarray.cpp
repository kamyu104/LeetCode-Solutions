// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = numeric_limits<int>::min();
        int min_product = 1, max_product = 1;
        for (const auto& num : nums) {
            tie(min_product, max_product) = pair(min({num, min_product * num, max_product * num}),
                                                 max({num, min_product * num, max_product * num}));
            result = max(result, max_product);
        }
        return result;
    }
};
