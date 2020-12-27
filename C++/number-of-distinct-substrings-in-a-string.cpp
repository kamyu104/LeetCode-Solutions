// Time:  O(n^2)
// Space: O(t), t is the number of trie nodes

class Solution {
public:
    int countDistinct(string s) {
        vector<array<int, 26>> trie(1);
        for (int i = 0; i < size(s); ++i) {
            int curr = 0;
            for (int j = i; j < size(s); ++j) {
                if (!trie[curr][s[j] - 'a']) {
                    trie.emplace_back();
                    trie[curr][s[j] - 'a'] = size(trie) - 1;
                }
                curr = trie[curr][s[j] - 'a'];
            }
        }
        return size(trie) - 1;
    }
};
