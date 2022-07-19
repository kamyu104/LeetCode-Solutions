// Time:  O(nlogr), r is max(nums)
// Space: O(n)

// greedy
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        const auto& sum_digits = [](int x) {
            int result = 0;
            for (; x; x /= 10) {
                result += x % 10;
            }
            return result;
        };
        unordered_map<int, int> lookup;
        int result = -1;
        for (const auto& x : nums) {
            const int k = sum_digits(x);
            if (!lookup.count(k)) {
                lookup[k] = x;
                continue;
            }
            result = max(result, lookup[k] + x);
            if (x > lookup[k]) {
                lookup[k] = x;
            }
        }
        return result;
    }
};
