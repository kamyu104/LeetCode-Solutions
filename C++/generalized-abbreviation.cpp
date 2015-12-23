// Time:  O(n * 2^n)
// Space: O(n)

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        string cur;
        generateAbbreviationsHelper(word, 0, &cur, &res);
        return res;
    }

    void generateAbbreviationsHelper(const string& word, int i, string *cur, vector<string> *res) {
        if (i == word.length()) {
            res->emplace_back(*cur);
            return;
        }
        cur->push_back(word[i]);
        generateAbbreviationsHelper(word, i + 1, cur, res);
        cur->pop_back();
        if (cur->empty() || not isdigit(cur->back())) {
            for (int len = 1; i + len <= word.length(); ++len) {
                cur->append(to_string(len));
                generateAbbreviationsHelper(word, i + len, cur, res);
                cur->resize(cur->length() - to_string(len).length());
            }
        }
    }
};
