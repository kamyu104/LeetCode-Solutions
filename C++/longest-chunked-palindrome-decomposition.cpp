// Time:  O(n)
// Space: O(1)

// Rabin-Karp Algorithm
class Solution {
public:
    int longestDecomposition(string text) {  
        static const uint64_t MOD = 1e9 + 7;
        static const uint64_t D = 26;
        int result = 0;
        int left = 0, right = 0, l = 0;
        uint64_t pow_D = 1;
        for (int i = 0; i < text.length(); ++i) {
            left = (D * left + (text[i] - 'a')) % MOD;
            right = (pow_D * (text[text.length() - 1 - i] - 'a') + right) % MOD;
            ++l;
            pow_D = (pow_D * D) % MOD;
            if (left == right &&
                compare(text, l, i - l + 1, text.length() - 1 - i)) {
                ++result;
                left = 0, right = 0, l = 0, pow_D = 1;
            }
        }
        return result;
    }

private:
    bool compare(const string& text, size_t l, int s1, int s2) {
        for (int i = 0; i < l; ++i) {
            if (text[s1 + i] != text[s2 + i]) {
                return false;
            }
        }
        return true;
    }
};
