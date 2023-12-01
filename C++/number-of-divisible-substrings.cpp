// Time:  O(d * n)
// Space: O(n)

// prefix sum, freq table
class Solution {
public:
    int countDivisibleSubstrings(string word) {
        int result = 0;
        for (int d = 1; d <= 9; ++d) {
            int prefix = 0;
            unordered_map<int, int> cnt = {{0 + d * (-1 + 1), 1}};
            for (int i = 0; i < size(word); ++i) {
                prefix += (word[i] - 'a' + 1) / 3 + 1;
                result += cnt[prefix - d * (i + 1)]++;
            }
        }
        return result;
    }
};
