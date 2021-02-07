// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int prev_with_square = 0, prev_without_square = 0;
        int result = 0;
        for (const auto& num : nums) {
            int without_square = max(num, num + prev_without_square);
            int with_square = max({num * num, num * num + prev_without_square, prev_with_square + num});
            result = max(result, with_square);
            prev_with_square = with_square;
            prev_without_square = without_square;
        }
        return result;
    }
};
