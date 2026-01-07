// Time:  O(mlogm)
// Space: O(m)

// sort, prefix sum, two pointers
class Solution {
public:
    int numberOfWays(int n, vector<int>& limit) {
        static const int MOD = 1e9 + 7;

        ranges::sort(limit);
        vector<int64_t> suffix(size(limit) + 1);        
        for(int i = size(limit) - 1; i >= 0; i--) {
            limit[i] = min(limit[i], n - 1);
            suffix[i] = suffix[i + 1] + limit[i];
        }
        int64_t result = 0;
        for (int i = size(limit) - 1, j = 0; i >= 0; --i) {
            for (; j < size(limit); ++j) {
                if (limit[i] + limit[j] >= n) {
                    break;
                }
            }
            int64_t cnt = (limit[i] - n + 1) * (size(limit) - j)  + suffix[j];
            if (i >= j) {
                cnt -= limit[i] + limit[i] - n + 1;
            }
            result = (result + cnt) % MOD;
        }
        return result;
    }
};
