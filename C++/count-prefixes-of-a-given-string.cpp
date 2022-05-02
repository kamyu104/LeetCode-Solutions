// Time:  O(n * l)
// Space: O(1)

// string
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        const auto& startsWith = [](const auto& s, const auto& prefix) {
            return (size(prefix) <= size(s) && s.compare(0, size(prefix), prefix, 0, size(prefix)) == 0);
        };
        return accumulate(cbegin(words), cend(words), 0,
                          [&](const auto& total, const auto& x) {
                              return total + startsWith(s, x);
                          });
    }
};
