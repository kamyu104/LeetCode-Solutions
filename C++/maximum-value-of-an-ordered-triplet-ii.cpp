// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        static const int NEG_INF = numeric_limits<int64_t>::min();

        int64_t result = 0;
        int64_t mx_diff = NEG_INF, mx = NEG_INF;
        for (const int64_t x : nums) {
            if (mx_diff != NEG_INF) {
                result = max(result, mx_diff * x);
            }
            if (mx != NEG_INF) {
                mx_diff = max(mx_diff, mx - x);
            }
            mx = max(mx, x);
        }
        return result;
    }
};
