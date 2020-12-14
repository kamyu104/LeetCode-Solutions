// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int result = size(words);
        vector<bool> lookup(26);
        for (const auto& c: allowed) {
            lookup[c - 'a'] = true;
        }
        for (const auto& word: words) {
            for (const auto& c: word) {
                if (!lookup[c - 'a']) {
                    --result;
                    break;
                }
            }
        }
        return result;
    }
};
