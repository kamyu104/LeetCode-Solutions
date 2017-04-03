// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> matches(n);
        for (int i = 0; i < n; ++i) {
            matches[i] = to_string(i + 1);
        }
        while (matches.size() / 2) {
            vector<string> next_matches;
            for (int i = 0; i < matches.size() / 2; ++i) {
                 next_matches.emplace_back("(" + matches[i] + "," + matches[matches.size() - 1 - i] + ")");
            }
            swap(matches, next_matches);
        }
        return matches[0];
    }
};
