// Time:  O(n * l^2 + n * r), l is the max length of the words, 
//                            r is the number of the results.
// Space: O(n^2)

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        const int n = s.length();

        size_t max_len = 0;
        for (const auto& str: wordDict) {
            max_len = max(max_len, str.length());
        }

        vector<bool> canBreak(n + 1, false);
        vector<vector<bool>> valid(n, vector<bool>(n, false));
        canBreak[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int l = 1; l <= max_len && i - l >= 0; ++l) {
                if (canBreak[i - l] && wordDict.count(s.substr(i - l, l))) {
                    valid[i - l][i - 1] = true;
                    canBreak[i] = true;
                }
            }
        }

        vector<string> result, path;
        if (canBreak[n]) {
            wordBreakHelper(s, valid, 0, &path, &result);
        }
        return result;
    }

    
    void wordBreakHelper(const string& s, const vector<vector<bool>>& valid,
                         int start, vector<string> *path, vector<string> *result) {
        if (start == s.length()) {
            string tmp;
            for (const auto& str : *path) {
                tmp += str;
                tmp += " ";
            }
            tmp.pop_back();
            result->emplace_back(move(tmp));
            return;
        }
        for (int i = start; i < s.length(); ++i) {
            if (valid[start][i]) {
                path->emplace_back(s.substr(start, i + 1 - start));
                wordBreakHelper(s, valid, i + 1, path, result);
                path->pop_back();
            }
        }
    }
};
