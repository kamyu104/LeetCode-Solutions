// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> cnt;
        int mx = 0;
        for (int i = 0; i < size(word); i += k) {
            mx = max(mx, ++cnt[word.substr(i, k)]);
        }
        return size(word) / k - mx;
    }
};
