// Time:  O(n)
// Space: O(n)

// freq table, prefix sum
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        static const int L = 3;

        int64_t result = 0;
        unordered_map<int, unordered_map<int64_t, int>> cnt;
        for (int64_t i = 0, prefix = 0, prefix2 = 0; i < size(capacity); ++i) {
            result += cnt[capacity[i]][prefix - capacity[i]];
            prefix += capacity[i];
            if ((i + 1) - L + 1 >= 0) {
                prefix2 += capacity[(i + 1) - L + 1];
                ++cnt[capacity[(i + 1) - L + 1]][prefix2];
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// freq table, prefix sum
class Solution2 {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int64_t result = 0;
        unordered_map<int, unordered_map<int64_t, int>> cnt;
        for (int64_t i = 0, prefix = 0; i < size(capacity); ++i) {
            result += cnt[capacity[i]][prefix - capacity[i]];
            prefix += capacity[i];
            ++cnt[capacity[i]][prefix];
            if (capacity[i] == 0 && i - 1 >= 0 && capacity[i - 1] == 0) {
                --result;
            }
        }
        return result;
    }
};
