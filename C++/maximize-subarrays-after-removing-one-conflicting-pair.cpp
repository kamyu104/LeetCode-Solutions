// Time:  O(n + m)
// Space: O(n + m)

// greedy
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int64_t>> right(n);
        for (const auto& p : conflictingPairs) {
            int l = p[0] - 1, r = p[1] - 1;
            if (l > r) {
                swap(l, r);
            }
            right[r].emplace_back(l);
        }
        int64_t result = 0;
        vector<int64_t> top2(2, -1);
        vector<int64_t> cnt(n);
        for (int r = 0; r < n; ++r) {
            for (auto l : right[r]) {
                for (int i = 0; i < size(top2); ++i) {
                    if (l > top2[i]) {
                        swap(l, top2[i]);
                    }
                }
            }
            result += r - top2[0];
            if (top2[0] != -1) {
                cnt[top2[0]] += top2[0] - top2[1];
            }
        }
        return result + ranges::max(cnt);
    }
};
