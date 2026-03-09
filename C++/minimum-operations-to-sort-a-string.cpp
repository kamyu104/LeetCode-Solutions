// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minOperations(string s) {
        if (is_sorted(cbegin(s), cend(s))) {
            return 0;
        }
        if (size(s) == 2) {
            return -1;
        }
        const auto& [mn, mx] = minmax_element(next(cbegin(s)), prev(cend(s)));
        return (s[0] == ranges::min(s) || s.back() == ranges::max(s)) ? 1 : ((s[0] <= *mx || s.back() >= *mn) ? 2 : 3);
    }
};
