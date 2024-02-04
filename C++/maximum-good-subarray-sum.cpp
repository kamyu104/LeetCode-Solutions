// Time:  O(n)
// Space: O(n)

// prefix sum
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        const auto NEG_INF = numeric_limits<int64_t>::min();
        const auto POS_INF = numeric_limits<int64_t>::max();

        unordered_map<int, int64_t> prefix;
        int64_t result = NEG_INF, curr = 0;
        for (const auto& x : nums) {
            prefix[x] = min(prefix.count(x) ? prefix[x] : POS_INF, curr);
            curr += x;
            if (prefix.count(x - k)) {
                result = max(result, curr - prefix[x - k]);
            }
            if (prefix.count(x + k)) {
                result = max(result, curr - prefix[x + k]);
            }
        }
        return result != NEG_INF ? result : 0;
    }
};
