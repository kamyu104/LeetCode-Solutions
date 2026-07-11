// Time:  O(n)
// Space: O(n)

// prefix sum, manacher's algorithm
class Solution {
public:
    long long getSum(vector<int>& nums) {
        const auto& manacher = [](const vector<int>& s) {
            const auto& preProcess = [](const vector<int>& s) {
                vector<int> ret = {-1};
                for (int i = 0; i < size(s); ++i) {
                    ret.emplace_back(-2);
                    ret.emplace_back(s[i]);
                }
                ret.emplace_back(-2);
                ret.emplace_back(-3);
                return ret;
            };

            vector<int> T = preProcess(s);
            const int n = size(T);
            vector<int> P(n);
            int C = 0, R = 0;
            for (int i = 1; i < n - 1; ++i) {
                int i_mirror = 2 * C - i;
                P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
                while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                    ++P[i];
                }
                if (i + P[i] > R) {
                    C = i;
                    R = i + P[i];
                }
            }
            return P;
        };

        vector<int64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<int> p = manacher(nums);
        int64_t result = 0;
        for (int i = 1; i + 1 < size(p); ++i) {
            result = max(result, prefix[(i + p[i]) / 2] - prefix[(i - p[i]) / 2]);
        }
        return result;
    }
};
