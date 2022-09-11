// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int partitionString(string s) {
        int result = 1, left = 0;
        vector<int> lookup(26, -1);
        for (int i = 0; i < size(s); ++i) {
            if (lookup[s[i] - 'a'] >= left) {
                left = i;
                ++result;
            }
            lookup[s[i] - 'a'] = i;
        }
        return result;
    }
};
