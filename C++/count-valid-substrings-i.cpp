// Time:  O(n)
// Space: O(1)

// combinatorics
class Solution {
public:
    long long countValidSubstrings(string s) {
        int64_t result = 0, l = 0;
        for (int i = 0; i < size(s); ++i) {
            ++l;
            if (!(i - 2 >= 0 && s.substr(i - 2, 3) == "abc")) {
                continue;
            }
            result += (l - 1) * l / 2 - 1; 
            l = 2;
        }
        result += l * (l + 1) / 2;
        return result;
    }
};
