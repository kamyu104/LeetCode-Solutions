// Time:  ctor:   O(n), n is number of words in the dictionary. 
//        lookup: O(1)
// Space: O(k), k is number of unique words.

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& word : dictionary) {
            const string abbr = abbreviation(word);
            lookup_[abbr].emplace(word);
        }
    } 

    bool isUnique(string word) {
        const string abbr = abbreviation(word);
        return lookup_[abbr].empty() ||
               (lookup_[abbr].count(word) == lookup_[abbr].size());
    }

private:
    unordered_map<string, unordered_set<string>> lookup_;

    string abbreviation(const string& word) {
        if (word.length() <= 2) {
            return word;
        }
        return word.front() + to_string(word.length()) + word.back();
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
