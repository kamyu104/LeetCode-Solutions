// Time:  O(n)
// Space: O(1)

// combinatorics
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        static const int MOD = 1e9 + 7;

        const auto& factorial = [&](int n) {
            int64_t result = 1;
            for (int i = 1; i <= n; ++i) {
                result = (result * i) % MOD;
            }
            return result;
        };

        return all_of(cbegin(complexity) + 1, cend(complexity), [&](const auto& x) {
            return complexity[0] < x;
        }) ? factorial(size(complexity) - 1) : 0;
    }
};
