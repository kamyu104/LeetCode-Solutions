// Time:  O(nlogn)
// Space: O(1)

// sort, array
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        static const int MOD = 1e9 + 7;

        sort(begin(ranges), end(ranges));
        int result = 1;
        int curr = numeric_limits<int>::min();
        for (const auto& r : ranges) {
            if (r[0] > curr) {
                result = (result * 2) % MOD;
            }
            curr = max(curr, r[1]);
        }
        return result;
    }
};
