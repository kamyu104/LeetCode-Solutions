// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        if (sentence.compare(0, searchWord.size(), searchWord) == 0) {
            return 1;
        }
        searchWord = " " + searchWord;
        auto p = KMP(sentence, searchWord);
        if (p == -1) {
            return -1;
        }
        return 1 + accumulate(cbegin(sentence), cbegin(sentence) + p + 1, 0,
                              [](const auto& a, const auto& b) {
                                  return a + (b == ' ');
                              });
    }

private:
    int KMP(const string& text, const string& pattern) {
        const vector<int> prefix = getPrefix(pattern);
        int j = -1;
        for (int i = 0; i < text.length(); ++i) {
            while (j > -1 && pattern[j + 1] != text[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i]) {
                ++j;
            }
            if (j == pattern.length() - 1) {
                return i - j;
            }
        }
        return -1;
    }

    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};
