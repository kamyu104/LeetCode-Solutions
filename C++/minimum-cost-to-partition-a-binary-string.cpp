// Time:  O(n)
// Space: O(n)

// prefix sum, divide and conquer
class Solution {
public:
    long long minCost(string s, int encCost, int flatCost) {
        vector<int64_t> prefix(size(s) + 1);
        const auto divide_and_conquer = [&](this auto&& divide_and_conquer, int left, int right) -> int64_t {
            const auto& l = right - left + 1;
            const auto& x = prefix[right + 1] - prefix[left];
            int64_t result = x ? l * x * encCost : flatCost;
            if (x && l % 2 == 0) {
                result = min(result, divide_and_conquer(left, (left + l / 2) - 1) + divide_and_conquer(left + l / 2, right));
            }
            return result;
        };

        for (int i = 0; i < size(s); ++i) {
            prefix[i + 1] = prefix[i] + (s[i] == '1' ? 1 : 0);
        }
        return divide_and_conquer(0, size(s) - 1);
    }
};
