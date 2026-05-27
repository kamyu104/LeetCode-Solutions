// Time:  O(n + k)
// Space: O(k)

// freq table, sliding window
class Solution {
public:
    long long minOperations(vector<int>& nums, int k) {
        const auto& topk = [](const vector<int64_t>& nums, int k) {  // Time: O(k * n)
            vector<pair<int64_t, int>> result(k, pair(numeric_limits<int64_t>::max(), numeric_limits<int>::max()));
            for (int i = 0; i < size(nums); ++i) {
                auto x = pair(nums[i], i);
                for (auto& y : result) {
                    if (x < y) {
                        swap(x, y);
                    }
                }
            }
            return result;
        };

        const auto& distance = [&](const auto& cnt) {
            const auto& total = accumulate(cbegin(cnt), cend(cnt), 0);
            int c = accumulate(cbegin(cnt) + 1, cbegin(cnt) + (k / 2 + 1), 0);
            vector<int64_t> dist(k);
            for (int i = 0; i < size(cnt); ++i) {
                dist[0] += cnt[i] * min(i, k - i);
            }
            for (int i = 1; i < size(dist); ++i) {
                dist[i] = dist[i - 1] - c + (total - c) - (k % 2 ? cnt[(i + k / 2) % k] : 0);
                c += cnt[(i + k / 2) % k] - cnt[i];
            }
            return dist;
        };

        vector<vector<int>> cnt(2, vector<int>(k));
        for (int i = 0; i < size(nums); ++i) {
            ++cnt[i % 2][nums[i] % k];
        }
        vector<vector<int64_t>> dist(2);
        for (int i = 0; i < 2; ++i) {
            dist[i] = distance(cnt[i]);
        }
        vector<vector<pair<int64_t, int>>> top2(2);
        for (int i = 0; i < 2; ++i) {
            top2[i] = topk(dist[i], 2);
        }
        return top2[0][0].second == top2[1][0].second ? min(top2[0][0].first + top2[1][1].first, top2[0][1].first + top2[1][0].first) : top2[0][0].first + top2[1][0
].first;

    }
};
