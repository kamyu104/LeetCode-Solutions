// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;
        
        for (int i = 31; i >= 0; --i) {
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
};
