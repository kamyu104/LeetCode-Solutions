// Time:  O(n * k)
// Space: O(n)

// freq table
class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        static const int64_t MAX_Y = 1e6;
        int result = 0;
        unordered_map<int64_t, int> cnt;
        for (const auto& x : coordinates) {
            for (int i = 0; i <= k; ++i) {
                result += cnt.count((x[0] ^ i) * (MAX_Y + 1) + (x[1] ^ (k - i))) ? cnt[(x[0] ^ i) * (MAX_Y + 1) + (x[1] ^ (k - i))] : 0; 
            }
            ++cnt[x[0] * (MAX_Y + 1) + x[1]];
        }
        return result;
    }
};
