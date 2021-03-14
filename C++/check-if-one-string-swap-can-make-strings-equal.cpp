// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<pair<int, int>> diff;
        for (int i = 0; i < size(s1); ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }
            if (size(diff) == 2) {
                return false;
            }
            diff.emplace_back(empty(diff) ? pair(s1[i], s2[i]) : pair(s2[i], s1[i]));
        }
        return empty(diff) || (size(diff) == 2 && diff[0] == diff[1]);
    }
};
