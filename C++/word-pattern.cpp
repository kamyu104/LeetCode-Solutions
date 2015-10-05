// Time:  O(n)
// Space: O(c), c is unique count of pattern and words

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int word_cnt = str.empty() ? 0 : 1;
        for (const auto& c : str) {
            if (c == ' ') {
                ++word_cnt;
            }
        }
        if (pattern.size() != word_cnt) {
            return false;
        }

        unordered_map<string, char> word2pattern;
        unordered_map<char, string> pattern2word;
        int i = 0, j = 0;
        for (const auto& p : pattern) {
            j = str.find(" ", i);
            if (j == string::npos) {
                j = str.length();
            }
            const string word = str.substr(i, j - i);
            if (!word2pattern.count(word) && !pattern2word.count(p)) { 
                word2pattern[word] = p; 
                pattern2word[p] = word; 
            } else if (word2pattern[word] != p) {
                return false;
            }
            i = j + 1;
        }
        return true;
    }
};
