// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string sortSentence(string s) {
        vector<string> words = split(s, ' ');
        for (int i = 0; i < size(words); ++i) {
            while (words[i].back() - '1' != i) {
                swap(words[i], words[words[i].back() - '1']);
            }
        }
        string result;
        for (const auto& word : words) {
            result += word;
            result.back() = ' ';
        }
        result.pop_back();
        return result;
    }

private:
    vector<string> split(const string& s, const char delim) {
        vector<string> result;
        auto end = string::npos;
        do {
            const auto& start = end + 1;
            end = s.find(delim, start);
            result.emplace_back(s.substr(start, end - start));
        } while (end != string::npos); 
        return result;
    }
};
