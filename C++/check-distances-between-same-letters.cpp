// Time:  O(n)
// Space: O(1)

// hash table
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        for (int i = 0; i < size(s); ++i) {
            if ((i + distance[s[i] - 'a'] + 1) >= size(s) || s[i + distance[s[i] - 'a'] + 1] != s[i]) {
                return false;
            }
            distance[s[i] - 'a'] = -1;
        }
        return true;
    }
};
