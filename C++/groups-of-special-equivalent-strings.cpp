// Time:  O(n * l)
// Space: O(n)

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> lookup;
        for (const auto& s: A) {
            string count(52, 0);
            for (int i = 0; i < s.length(); ++i) {
                ++count[s[i] - 'a' + 26 * (i % 2)];
            }
            lookup.emplace(count);
        }
        return lookup.size();
    }
};
