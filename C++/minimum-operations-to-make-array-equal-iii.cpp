// Time:  O(nlogr), r = max(nums)
// Space: O(n)

// freq table, bit manipulation
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        unordered_map<int, unordered_map<int, int>> cnt;
        for (const auto& x : nums) {
           ++cnt[bit_width(static_cast<uint32_t>(x))][x];
        }
        if (cnt[1].count(1) && cnt[1][1] == size(nums)) {
            return 0;
        }
        vector<int> candidates;
        for (const auto& [l, b] : cnt) {
            if (l == 1) {
                continue;
            }
            int total = 0;
            for (const auto& [_, c] : b) {
                total += c;
            }
            for (const auto& [x, c] : b) {
                if (total - 2 * c >= 0) {
                    continue;
                }
                candidates.emplace_back(x);
                break;
            }
        }
        int result = size(nums);
        for (const auto& target : candidates) {
            int c = 0;
            for (const auto& x : nums) {
                if (x == target) {
                    continue;
                }
                if (x % target == 0 || target % x == 0) {
                    ++c;
                } else {
                    c += 2;
                }
            }
            result = min(result, c);
        }
        return result;
    }
};
