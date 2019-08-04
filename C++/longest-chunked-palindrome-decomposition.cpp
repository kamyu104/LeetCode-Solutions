// Time:  O(n)
// Space: O(1)

// Rabin-Karp Algorithm
class Solution {
public:
    Solution() : pow_(N_ + 1, 1) {
        for (int i = 1; i < pow_.size(); ++i) {
            pow_[i] = (pow_[i - 1] * D_) % MOD_;
        }
    }

    int longestDecomposition(string text) {
        int result = 0;
        int l = 0, left = 0, right = 0;
        for (int i = 0; i < text.length(); ++i) {
            ++l;
            left = (pow_[1] * left + (text[i] - 'a')) % MOD_;
            right = (pow_[l - 1] * (text[text.length() - 1 - i] - 'a') + right) % MOD_;
            if (left == right &&
                compare(text, l, i - l + 1, text.length() - 1 - i)) {
                ++result;
                l = 0, left = 0, right = 0;
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

    vector<uint64_t> pow_;
    static const int N_ = 1000;
    static const uint64_t MOD_ = 1e9 + 7;
    static const uint64_t D_ = 26;
};
