// Time:  O(26 * n) = O(n)
// Space: O(26 * n) = O(n)

class Solution {
public:
    string longestNiceSubstring(string s) {
        array<array<int, 2>, 26> lookup = {0};
        for (const auto& c : s) {
            lookup[tolower(c) - 'a'][isupper(c) != 0] = 1;
        }
        string result;
        for (int i = 0, prev = -1; i <= size(s); ++i) {
            if (!(i == size(s) || !lookup[tolower(s[i]) - 'a'][0] || !lookup[tolower(s[i]) - 'a'][1])) {
                continue;
            }
            if (prev == -1 && i == size(s)) {
                return s;
            }
            auto tmp = longestNiceSubstring(s.substr(prev + 1, i - prev - 1));
            if (size(tmp) > size(result)) {
                result = move(tmp);
            }
            prev = i;
        }
        return result;
    }
};
