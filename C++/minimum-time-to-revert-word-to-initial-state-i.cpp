// Time:  O(n)
// Space: O(n)

// z-function
class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };

        // Template: https://cp-algorithms.com/string/z-function.html
        const auto& z_function = [](const string& s) {  // Time: O(n), Space: O(n)
            vector<int> z(size(s));
            for (int i = 1, l = 0, r = 0; i < size(z); ++i) {
                if (i <= r) {
                    z[i] = min(r - i + 1, z[i - l]);
                }
                while (i + z[i] < size(z) && s[z[i]] == s[i + z[i]]) {
                    ++z[i];
                }
                if (i + z[i] - 1 > r) {
                    l = i, r = i + z[i] - 1;
                }
            }
            return z;
        };

        const auto& z = z_function(word);
        for (int i = k; i < size(word); i += k) {
            if (z[i] == size(word) - i) {
                return i / k;
            }
        }
        return ceil_divide(size(word), k);
    }
};

// Time:  O(n^2)
// Space: O(1)
// brute force
class Solution2 {
public:
    int minimumTimeToInitialState(string word, int k) {
        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };
        const auto& check = [&](int i) {
            for (int j = 0; i + j < size(word); ++j) {
                if (word[i + j] != word[j]) {
                    return false;
                }
            }
            return true;
        };

        for (int i = k; i < size(word); i += k) {
            if (check(i)) {
                return i / k;
            }
        }
        return ceil_divide(size(word), k);
    }
};
