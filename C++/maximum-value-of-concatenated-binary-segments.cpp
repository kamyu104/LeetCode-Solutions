// Time:  O(r + nlogn)
// Space: O(r + n)

// greedy
const int MOD = 1e9 + 7;
const auto& precompute = [](int r) {
    vector<int64_t> pow2(r + 1, 1);
    for (int i = 0; i + 1 < size(pow2); ++i) {
        pow2[i + 1] = (pow2[i] * 2) % MOD;
    }
    return pow2;
};

const int MAX_TOTAL = 2e5;
const auto& POW2 = precompute(MAX_TOTAL);
class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int, int>> segments;
        int l = 0;
        for (int i = 0; i < size(nums1); ++i) {
            if (nums0[i]) {
                segments.emplace_back(nums1[i], nums0[i]);
            } else {
                l += nums1[i];
            }
        }
        sort(begin(segments), end(segments), [](const auto& x, const auto& y) {
            return x.first == y.first ? x.second < y.second : x.first > y.first;
        });
        int64_t result = ((POW2[l] - 1) + MOD) % MOD;
        for (const auto& [cnt1, cnt0] : segments) {
            result = ((result * POW2[cnt1 + cnt0]) % MOD + ((((POW2[cnt1] - 1) + MOD) % MOD) * POW2[cnt0]) % MOD) % MOD;
        }
        return result;
    }
};
