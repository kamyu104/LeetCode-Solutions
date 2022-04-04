// Time:  O(n)
// Space: O(n)

// z-function
class Solution {
public:
    long long sumScores(string s) {
        auto z = z_function(s);
        z[0] = size(s);
        return accumulate(cbegin(z), cend(z), 0ll);
    }

private:
    // Template: https://cp-algorithms.com/string/z-function.html
    vector<int> z_function(string s) {  // Time: O(n), Space: O(n)
        vector<int> z(size(s));
        for (int i = 1, l = 0, r = 0; i < size(z); ++i) {
            if (i <= r) {
                z[i] = min (r - i + 1, z[i - l]);
            }
            while (i + z[i] < size(z) && s[z[i]] == s[i + z[i]]) {
                ++z[i];
            }
            if (i + z[i] - 1 > r) {
                l = i, r = i + z[i] - 1;
            }
        }
        return z;
    }
};
