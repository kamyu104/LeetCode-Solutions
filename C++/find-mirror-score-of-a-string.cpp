// Time:  O(n + 26)
// Space: O(n + 26)

// simulation, hash table, stack
class Solution {
public:
    long long calculateScore(string s) {
        int64_t result = 0;
        vector<vector<int>> lookup(26);
        for (int i = 0; i < size(s); ++i) {
            const int x = s[i] - 'a';
            if (!empty(lookup[25 - x])) {
                result += i - lookup[25 - x].back(); lookup[25 - x].pop_back();
            } else {
                lookup[x].emplace_back(i);
            }
        }
        return result;
    }
};
