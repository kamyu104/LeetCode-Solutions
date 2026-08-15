// Time:  O(n)
// Space: O(n)

// greedy, hash table
class Solution {
public:
    string mergeCharacters(string s, int k) {
        string result;
        vector<int> lookup(26, -1);
        for (const auto& x : s) {
            const auto& c = x - 'a';
            if (!(lookup[c] == -1 || size(result) - lookup[c] > k)) {
                continue;
            }
            lookup[c] = size(result);
            result.push_back(x);
        }
        return result;
    }
};
