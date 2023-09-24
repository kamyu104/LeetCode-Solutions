// Time:  O(n)
// Space: O(n)

// mono stack
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        vector<int64_t> left(size(maxHeights));
        vector<int64_t> stk = {-1};
        for (int64_t i = 0, curr = 0; i < size(maxHeights); ++i) {
            while (stk.back() != stk[0] && maxHeights[stk.back()] >= maxHeights[i]) {
                const int j = stk.back(); stk.pop_back();
                curr -= (j - stk.back()) * maxHeights[j];
            }
            curr += (i - stk.back()) * maxHeights[i];
            stk.emplace_back(i);
            left[i] = curr;
        }
        int64_t result = 0, right = 0;
        stk = {static_cast<int64_t>(size(maxHeights))};
        for (int64_t i = size(maxHeights) - 1, curr = 0; i >= 0; --i) {
            while (stk.back() != stk[0] && maxHeights[stk.back()] >= maxHeights[i]) {
                const int j = stk.back(); stk.pop_back();
                curr -= (stk.back() - j) * maxHeights[j];
            }
            curr += (stk.back() - i) * maxHeights[i];
            stk.emplace_back(i);
            right = curr;
            result = max(result, left[i] + right - maxHeights[i]);
        }
        return result;
    }
};
