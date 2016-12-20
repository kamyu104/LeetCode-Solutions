// Time:  O(n * l^2)
// Space: O(n * l)

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> lookup(words.begin(), words.end());
        vector<string> result;
        for (const auto& word : words) {
            vector<bool> dp(word.length() + 1);
            dp[0] = true;
            for (int i = 0; i < word.length(); ++i) {
                if (!dp[i]) {
                    continue;
                }
                for (int j = i + 1; j <= word.length(); ++j) {
                    if (j - i < word.length() && lookup.count(word.substr(i, j - i))) {
                        dp[j] = true;
                    }
                }
                if (dp[word.length()]) {
                    result.emplace_back(word);
                    break;
                }
            }
        }
        return result;
    }
};
