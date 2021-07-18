// Time:  O(nlogk), k is max(nums)
// Space: O(nlogk)

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;
        
        for (int i = bit_length(*max_element(cbegin(nums), cend(nums))); i >= 0; --i) {
            result <<= 1;
            unordered_set<int> prefixes;
            for (const auto& n : nums) {
                prefixes.emplace(n >> i);
            }
            for (const auto& p : prefixes) {
                if (prefixes.count((result | 1) ^ p)) {
                    ++result;
                    break;
                }
            }
        }

        return result;
    }

private:
    int bit_length(int x) {
        return x != 0 ? 32 - __builtin_clz(x) : 1;
    }
};
