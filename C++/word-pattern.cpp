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
        for (int i = 0, idx = 0, space_idx = 0;
             i < pattern.size();
             ++i, idx = space_idx + 1) {
                 
            space_idx = str.find(" ", idx) != string::npos ?
                        str.find(" ", idx) :
                        str.length();
            string word = str.substr(idx, space_idx - idx);
            if (word2pattern[word] == 0 &&
                pattern2word[pattern[i]] == "") { 
                word2pattern[word] = pattern[i]; 
                pattern2word[pattern[i]] = word; 
            } else if (word2pattern[word] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};
