// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int result = numeric_limits<int>::min();
        int prev = numeric_limits<int>::min();
        int curr = numeric_limits<int>::min();
        for (const auto &x : arr) {
            curr = max(prev, (curr == numeric_limits<int>::min()) ? x : max(curr + x, x));
            result = max(result, curr);
            prev = (prev == numeric_limits<int>::min()) ? x : max(prev + x, x);
        }
        return result;
    }
};
