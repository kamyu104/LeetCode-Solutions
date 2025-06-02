// Time:  O(n)
// Space: O(26)

// greedy, hash table
class Solution {
public:
    int maxSubstrings(string word) {
        static const int L = 4;

        int result = 0;
        unordered_map<char, int> lookup;
        for (int i = 0; i < size(word); ++i) {
            if (!lookup.count(word[i])) {
                lookup[word[i]] = i;
            } else if (i - lookup[word[i]] + 1 >= L) {
                ++result;
                lookup.clear();
            }
        }
        return result;
    }
};
