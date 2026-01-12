// Time:  O(n + 26)
// Space: O(26)

// hash table
class Solution {
public:
    int residuePrefixes(string s) {
        int result = 0;
        vector<bool> lookup(26);
        for (int i = 0, distinct = 0; i < size(s); ++i) {
            if (!lookup[s[i] - 'a']) {
                if (++distinct >= 3) {
                    break;
                }
            }
            lookup[s[i] - 'a'] = true;
            if (distinct == (i + 1) % 3) {
                ++result;
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(3)
// hash table
class Solution2 {
public:
    int residuePrefixes(string s) {
        int result = 0;
        unordered_set<int> lookup;
        for (int i = 0; i < size(s); ++i) {
            lookup.emplace(s[i]);
            if (size(lookup) >= 3) {
                break;
            }
            if (size(lookup) == (i + 1) % 3) {
                ++result;
            }
        }
        return result;
    }
};
