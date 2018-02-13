// Time:  O((d * l) * logd), l is the average length of words
// Space: O(1)

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), 
             [](const string& a, const string&b) {
                return a.length() != b.length() ? a.length() > b.length() : a < b;
             });

        for (const auto& word : d) {
            int i = 0;
            for (const auto& c : s) {
                if (i < word.length() && word[i] == c) {
                    ++i;
                }
            }
            if (i == word.length()) {
                return word;
            }
        }
        return "";
    }
};
