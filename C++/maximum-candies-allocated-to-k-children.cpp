// Time:  O(nlogr), r is max(candies)
// Space: O(1)

// binary search
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        const auto& check = [&candies, &k](const auto& x) {
            return accumulate(cbegin(candies), cend(candies), 0ll,
                              [&x](const auto& total, const auto& v) {
                                  return total + v / x;
                              }) >= k;
        };
        int left = 1, right = *max_element(cbegin(candies), cend(candies));
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (!check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
