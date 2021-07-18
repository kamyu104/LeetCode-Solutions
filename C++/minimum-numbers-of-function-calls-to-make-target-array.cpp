// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0, max_len = 0;
        for (const auto& num : nums) {
            result += __builtin_popcount(num);
            max_len = max(max_len, bit_length(num));
        }
        return result + max_len - 1;
    }

private:
    int bit_length(int x) {
        return x != 0 ? 32 - __builtin_clz(x) : 1;
    }
};
