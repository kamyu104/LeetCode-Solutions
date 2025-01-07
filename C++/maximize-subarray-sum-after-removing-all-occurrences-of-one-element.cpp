// Time:  O(n)
// Space: O(n)

// hash table, greedy, kadane's algorithm
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums) {
        int64_t result = numeric_limits<int64_t>::min();
        int64_t curr = 0, mn = 0, mn0 = 0;
        unordered_map<int, int64_t> mn1;        
        for (const auto& x: nums) {
            curr += x;
            result = max(result, curr - mn);
            mn1[x] = min(mn1[x], mn0) + x;
            mn0 = min(mn0, curr);
            mn = min({mn, mn1[x], mn0});
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// hash table, greedy, kadane's algorithm
class Solution2 {
public:
    long long maxSubarraySum(vector<int>& nums) {
        int64_t result = numeric_limits<int64_t>::min();
        int64_t curr = 0, mn = 0, mn0 = 0;
        unordered_map<int, int64_t> mn1;        
        for (const auto& x: nums) {
            curr += x;
            result = max(result, curr - mn);
            if (x < 0) {
                mn1[x] = min(mn1[x], mn0) + x;
                mn = min(mn, mn1[x]);
            }
            mn0 = min(mn0, curr);
            mn = min(mn, mn0);
        }
        return result;
    }
};
