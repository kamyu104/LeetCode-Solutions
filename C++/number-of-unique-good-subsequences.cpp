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
                ends1 = (ends0 + ends1 + 1) % MOD;  // curr subsequences end with 1 is all prev distinct subsequences appended by 1 and plus "1"
            } else {
                ends0 = (ends0 + ends1) % MOD;  // curr subsequences end with 0 is all prev distinct subsequences appended by 0 and don't plus "0"
                has_zero = true;
            }
        }
        return (ends0 + ends1 + int(has_zero)) % MOD;  // add "0" if has_zero
    }
};
