// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> result;
        for (int64_t base = 1; n; n /= 10, base *= 10) {
            const auto& r = n % 10;
            if (r) {
                result.emplace_back(r * base);
            }
        }
        reverse(begin(result), end(result));
        return result;
    }
};
