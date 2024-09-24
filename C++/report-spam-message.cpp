// Time:  O(n + m)
// Space: O(m)

// hash table
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> lookup(cbegin(bannedWords), cend(bannedWords));
        int cnt = 0;
        for (const auto& m : message) {
            if (!lookup.count(m)) {
                continue;
            }
            if (++cnt == 2) {
                break;
            }
        }
        return cnt == 2;
    }
};
