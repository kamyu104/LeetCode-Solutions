// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    string arrangeWords(string text) {
        text.front() = tolower(text.front());
        stringstream ss(text);
        string word;
        map<int, string> lookup;
        while (ss >> word) {
            lookup[word.size()] += word + " ";
        }
        string result;
        for (const auto& [_, word]: lookup) {
            result += word;
        }
        result.pop_back();
        result.front() = toupper(result.front());
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    string arrangeWords(string text) {
        text.front() = tolower(text.front());
        auto words = split(text, ' ');
        stable_sort(begin(words), end(words),
                    [](const string &s1, const string &s2) {
                        return s1.size() < s2.size();
                    });
        string result;
        for (const auto& word : words) {
            result += word + " ";
        }
        result.pop_back();
        result.front() = toupper(result.front());
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
