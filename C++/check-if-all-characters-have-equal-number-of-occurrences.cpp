// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<int, int> lookup;
        for (const auto& c : s) {
            ++lookup[c];
        }
        return std::adjacent_find(
            cbegin(lookup), cend(lookup),
            [](const auto& a, const auto& b) {
                return a.second != b.second;
            }) == cend(lookup);
    }
};
