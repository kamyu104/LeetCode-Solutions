// Time:  O(n)
// Space: O(1)

// hash table
class Solution {
public:
    char repeatedCharacter(string s) {
        char result = 0;
        vector<bool> lookup(26);
        for (const auto& c : s) {
            if (lookup[c - 'a']) {
                result = c;
                break;
            }
            lookup[c - 'a'] = true;
        }
        return result;
    }
};
