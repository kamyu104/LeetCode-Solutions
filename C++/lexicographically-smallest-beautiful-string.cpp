// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        const auto& check = [&](int i) {
            return (i - 1 < 0 || s[i - 1] != s[i]) && (i - 2 < 0 || s[i - 2] != s[i]);
        };

        int i = size(s) - 1;
        for (; i >= 0; --i) {
            for (++s[i]; !check(i); ++s[i]);
            if (s[i] - 'a' < k) {
                break;
            }
        }
        if (i < 0) {
            return "";
        }
        for (int j = i + 1; j < size(s); ++j) {
            s[j] = 'a';
            while (!check(j)) {
                ++s[j];
            }
        }
        return s;
    }
};
