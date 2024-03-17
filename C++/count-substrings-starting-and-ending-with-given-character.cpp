// Time:  O(n)
// Space: O(1)

// combinatorics
class Solution {
public:
    long long countSubstrings(string s, char c) {
        const int64_t n = count(cbegin(s), cend(s), c);
        return (n + 1) * n / 2;
    }
};
