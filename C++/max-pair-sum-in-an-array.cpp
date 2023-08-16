// Time:  O(nlogr)
// Space: O(1)

// hash table
class Solution {
public:
    int maxSum(vector<int>& nums) {
        const auto& max_digit = [](int x) {
            int result = 0;
            for (; x; x /= 10) {
                result = max(result, x % 10);
            }
            return result;
        };

        int result = -1;
        vector<int> lookup(10, -1);
        for (const auto& x : nums) {
            const int mx = max_digit(x);
            if (lookup[mx] == -1) {
                lookup[mx] = x;
                continue;
            }
            result = max(result, lookup[mx] + x);
            lookup[mx] = max(lookup[mx], x);
        }
        return result;
    }
};
