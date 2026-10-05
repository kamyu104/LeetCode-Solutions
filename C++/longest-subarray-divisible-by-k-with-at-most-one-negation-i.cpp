// Time:  O(n + k^2)
// Space: O(k)

// prefix sum, hash table
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        static const auto& INF = numeric_limits<int>::max();

        vector<int> lookup = {0};
        vector<int> left(k, -1);
        left[0] = 0;
        vector<int> idxs(k);
        vector<int> mn(k, INF);
        int result = 0;
        for (int right = 0, prefix = 0; right < size(nums); ++right) {
            const auto& x = ((nums[right] % k) + k) % k;
            const auto& v = (2 * x) % k;
            for (int i = idxs[v]; i < size(lookup); ++i) {
                mn[(lookup[i] + v) % k] = min(mn[(lookup[i] + v) % k], left[lookup[i]]);
            }
            idxs[v] = size(lookup);
            prefix = (prefix + x) % k;
            if (left[prefix] != -1) {
                result = max(result, right - left[prefix] + 1);
            } else {
                lookup.emplace_back(prefix);
                left[prefix] = right + 1;
            }
            if (mn[prefix] != INF) {
                result = max(result, right - mn[prefix] + 1);
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(k)
// prefix sum, hash table, brute force
class Solution2 {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            unordered_set<int> lookup;
            for (int j = i, prefix = 0; j < size(nums); ++j) {
                prefix = (((prefix + nums[j]) % k) + k) % k;
                lookup.emplace(((2 * nums[j] % k) + k) % k);
                if (prefix == 0 || lookup.count(prefix)) {
                    result = max(result, j - i + 1);
                }
            }
        }
        return result;
    }
};
