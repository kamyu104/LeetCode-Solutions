// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        static const int MOD = 1e9 + 7;

        int ends0 = 0, ends1 = 0;
        bool has_zero = false;
        for (const auto& b : binary) {
            if (b == '1') {
                ends1 = (ends1 + ends0 + 1) % MOD;  // add extra ends0 new distinct subsequences and add one "1"
            } else {
                ends0 = (ends0 + ends1) % MOD;  // add extra ends1 new distinct subsequences and don't add one "0"
                has_zero = true;
            }
        }
        return (ends0 + ends1 + int(has_zero)) % MOD;  // add "0" if has_zero
    }
};
