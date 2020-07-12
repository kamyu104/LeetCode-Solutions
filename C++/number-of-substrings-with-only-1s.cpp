// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numSub(string s) {
        static const int MOD = 1e9 + 7;
        int result = 0, count = 0;
        for (const auto& c : s) {
            count = (c == '1') ? count + 1 : 0;
            result = (result + count) % MOD;
        }
        return result;
    }
};
