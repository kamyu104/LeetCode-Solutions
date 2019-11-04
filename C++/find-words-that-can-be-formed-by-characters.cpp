// Time:  O(m * n), m is the length of chars, n is the number of words
// Space: O(1)

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        const auto& count = counter(chars);
        int result = 0;
        for (const auto& word : words) {
            if (check(word, chars, count)) {
                result += word.length();
            }
        }
        return result;
    }

private:
    unordered_map<char, int> counter(const string& s) {
        unordered_map<char, int> result;
        for (const auto& c : s) {
            ++result[c];
        }
        return result;
    }
    
    bool check(const string& word, const string& chars,
               const unordered_map<char, int>& count) {
        if (word.length() > chars.length()) {
            return false;
        }
        unordered_map<char, int> curr_count;
        for (const auto& c : word) {
            ++curr_count[c];
            if (!count.count(c) || count.at(c) < curr_count[c]) {
                return false;
            }
        }
        return true;
    }
};
