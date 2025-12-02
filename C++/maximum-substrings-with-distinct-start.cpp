// Time:  O(n + 26)
// Space: O(26)

// hash table
class Solution {
public:
    int maxDistinct(string s) {
        int result = 0;
        vector<bool> lookup(26);
        for (const auto& x : s) {
            if (lookup[x - 'a']) {
                continue;
            }
            lookup[x - 'a'] = true;
            ++result;
        }
        return result;
    }
};

// Time:  O(n + 26)
// Space: O(26)
// hash table
class Solution2 {
public:
    int maxDistinct(string s) {
        return size(unordered_set<char>(cbegin(s), cend(s)));
    }
};
