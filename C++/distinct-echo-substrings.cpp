// Time:  O(n^2 + d), d is the duplicated of result substrings size
// Space: O(r), r is the size of result substrings set

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string> result;
        for (int l = 1; l <= text.length() / 2; ++l) {
            int count = 0;
            for (int i = 0; i < l; ++i) {
                count += int(text[i] == text[i + l]);
            }
            for (int i = 0; i < text.length() - 2 * l; ++i) {
                if (count == l) {
                    result.emplace(text.substr(i, l));
                }
                count += int(text[i + l] == text[i + l + l]) - int(text[i] == text[i + l]);
            }
            if (count == l) {
                result.emplace(text.substr(text.length() - 2 * l, l));
            }
        }
        return result.size();
    }
};

// Time:  O(n^2 + d), d is the duplicated of result substrings size
// Space: O(r), r is the size of result substrings set
class Solution2 {
public:
    int distinctEchoSubstrings(string text) {
        static int MOD = 1e9 + 7;
        int D = 27;  // a-z and ''
        unordered_set<uint64_t> result;
        for (int i = 0; i < text.length(); ++i) {
            uint64_t left = 0, right = 0, pow_D = 1;
            for (int l = 1; l < min(i + 2, int(text.length()) - i); ++l) {
                left = (D * left + text[i - l + 1] - 'a' + 1) % MOD;
                right = (pow_D * (text[i + l] - 'a' + 1) % MOD + right) % MOD;
                if (left == right) {  // assumed no collision
                    result.emplace(left);
                }
                pow_D = (pow_D * D) % MOD;
            }
        }
        return result.size();
    }
};

// Time:  O(n^3 + d), d is the duplicated of result substrings size
// Space: O(r), r is the size of result substrings set
class Solution_TLE {
public:
    int distinctEchoSubstrings(string text) {
        static int MOD = 1e9 + 7;
        int D = 27;  // a-z and ''
        unordered_set<string> result;
        for (int i = 0; i < text.length(); ++i) {
            uint64_t left = 0, right = 0, pow_D = 1;
            for (int l = 1; l < min(i + 2, int(text.length()) - i); ++l) {
                left = (D * left + text[i - l + 1] - 'a' + 1) % MOD;
                right = (pow_D * (text[i + l] - 'a' + 1) % MOD + right) % MOD;
                if (left == right && compare(text, l, i - l + 1, i + 1)) {
                    result.emplace(text.substr(i + 1, l));
                }
                pow_D = (pow_D * D) % MOD;
            }
        }
        return result.size();
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
