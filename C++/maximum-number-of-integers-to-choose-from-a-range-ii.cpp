// Time:  O(blogb + logn * logb)
// Space: O(b)

// binary search, prefix sum
class Solution {
public:
    int maxCount(vector<int>& banned, int n, long long maxSum) {
        sort(begin(banned), end(banned));
        vector<int64_t> prefix(size(banned) + 1);
        for (int i = 0; i < size(banned); ++i) {
            prefix[i + 1] = prefix[i] + banned[i];
        }
        const auto& check = [&](const int64_t x) {
            return (x + 1) * x / 2 - prefix[distance(cbegin(banned), upper_bound(cbegin(banned), cend(banned), x))] <= maxSum;
        };
        int left = 1, right = n;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (!check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } 
        return right - distance(cbegin(banned), upper_bound(cbegin(banned), cend(banned), right));
    }
};
