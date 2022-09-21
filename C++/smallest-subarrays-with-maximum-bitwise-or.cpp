// Time:  O(n)
// Space: O(1)

// bitmasks, hash table
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const auto& bit_length = [](int x) {
            return x != 0 ? 32 - __builtin_clz(x) : 1;
        };
        vector<int> result(size(nums));
        vector<int> lookup(bit_length(*max_element(cbegin(nums), cend(nums))), -1);
        for (int i = size(nums) - 1; i >= 0; --i) {
            for (int bit = 0; bit < size(lookup); ++bit) {
                if (nums[i] & (1 << bit)) {
                    lookup[bit] = i;
                }
            }
            result[i] = max(*max_element(cbegin(lookup), cend(lookup)) - i + 1, 1);
        }
        return result;
    }
};
