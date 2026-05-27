// Time:  O(n + m + q * sqrt(m * n)), n = len(nums1), m = len(nums2)
// Space: O(n + m)

// freq table, sqrt decomposition
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };

        vector<int64_t> nums(cbegin(nums2), cend(nums2));
        const auto& update = [&](unordered_map<int, int>& cnt, int left, int right, int val) {
            for (int i = left; i <= right; ++i) {
                --cnt[nums[i]];
                if (!cnt[nums[i]]) {
                    cnt.erase(nums[i]);
                }
                nums[i] += val;
                ++cnt[nums[i]];
            }
        };

        unordered_map<int, int> cnt1;
        for (const auto& x : nums1) {
            ++cnt1[x];
        }
        const auto& B = static_cast<int>(sqrt(size(cnt1) * size(nums2))) + 1;
        vector<unordered_map<int, int>> cnt2(ceil_divide(size(nums), B));
        for (int i = 0; i < size(cnt2); ++i) {
            for (int j = i * B, bound = min((i + 1) * B, static_cast<int>(size(nums))); j < bound; ++j) {
                ++cnt2[i][nums[j]];
            }
        }
        vector<int64_t> lazy(size(cnt2));
        vector<int> result;
        for (const auto& q : queries) {
            if (q[0] == 2) {
                const auto& tot = q[1];
                int total = 0;
                for (const auto& [x, c] : cnt1) {
                    for (int i = 0; i < size(cnt2); ++i) {
                        if (!cnt2[i].count((tot - x) - lazy[i])) {
                            continue;
                        }
                        total += cnt2[i][(tot - x) - lazy[i]] * c;
                    }
                }
                result.emplace_back(total);
                continue;
            }
            const auto& x = q[1], &y = q[2], &val = q[3];
            if (x / B == y / B) {
                update(cnt2[x / B], x, y, val);
                continue;
            }
            update(cnt2[x / B], x, ((x / B) + 1) * B - 1, val);
            for (int i = (x / B) + 1; i < y / B; ++i) {
                lazy[i] += val;
            }
            update(cnt2[y / B], (y / B) * B, y, val);
        }
        return result;
    }
};
