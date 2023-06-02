// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if (all_of(cbegin(nums), cend(nums), [](const auto& x) { return x <= 0; }) &&
            accumulate(cbegin(nums), cend(nums), 0ll, [](const auto& accu, const auto& x) { return accu + static_cast<int>(x < 0); }) <= 1) {
            return *max_element(cbegin(nums), cend(nums));
        }
        const int64_t result = accumulate(cbegin(nums), cend(nums), 1ll, [](const auto& accu, const auto& x) { return x != 0 ? accu * x : accu; });
        int mx = numeric_limits<int>::min();
        for (const auto& x : nums) {
            if (x < 0) {
                mx = max(mx, x);
            }
        }
        return result > 0 ? result : result / mx;
    }
};
