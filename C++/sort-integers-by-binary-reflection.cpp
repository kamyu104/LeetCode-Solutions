// Time:  O(nlogr + nlogn)
// Space: O(n)

// sort, bitmasks
class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        const auto& reverse = [](int x) {
            int result = 0;
            for (; x; x >>= 1) {
                result = (result << 1) | (x & 1);
            }
            return result;
        };

        vector<pair<int, int>> pairs;
        pairs.reserve(size(nums));
        for (const auto& x : nums) {
            pairs.emplace_back(reverse(x), x);
        }
        ranges::sort(pairs);
        vector<int> result;
        result.reserve(size(nums));
        for (const auto& [_, x] : pairs) {
            result.emplace_back(x);
        }
        return result;
    }
};
