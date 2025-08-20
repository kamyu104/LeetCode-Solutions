// Time:  O(nlogn)
// Space: O(1)

// Erdős–Gallai theorem, sort, prefix sum, two pointers
class Solution {
public:
    bool simpleGraphExists(vector<int>& degrees) {
        // reference: https://en.wikipedia.org/wiki/Erd%C5%91s%E2%80%93Gallai_theorem
        const auto& total = accumulate(cbegin(degrees), cend(degrees), 0LL);
        if (total % 2) {
            return false;
        }
        sort(begin(degrees), end(degrees), greater<int>());
        int64_t lhs = 0, suffix1 = total, suffix2 = 0;
        for (int k = 1, i = size(degrees) - 1; k <= size(degrees); ++k) {
            lhs += degrees[k - 1];
            suffix1 -= degrees[k - 1];
            for (; i >= 0 && degrees[i] < k; --i) {
                suffix2 += degrees[i];
            };
            const auto& rhs = static_cast<int64_t>(k) * (k - 1) + ((i - k + 1 > 0) ? static_cast<int64_t>(i - k + 1) * k + suffix2: suffix1);
            if (!(lhs <= rhs)) {
                return false;
            }
        }
        return true;
    }
};
