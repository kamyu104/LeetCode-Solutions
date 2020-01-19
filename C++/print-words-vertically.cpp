// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> result, words;
        stringstream ss(s);
        string word;
        int max_len = 0;
        while (ss >> word) {
            words.emplace_back(word);
            max_len = max(max_len, int(word.size()));
        }
        for (int i = 0; i < max_len; ++i) {
            result.emplace_back();
            for (const auto& word : words) {
                result.back() += i < word.length() ? word[i] : ' ';
            }
            while (result.back().back() == ' ') {
                result.back().pop_back();
            }
        }
        return result;
    }
};
