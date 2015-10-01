// Time:  O(n) for constructor, n is number of words in the dictionary. 
//        O(1) for lookup
// Space: O(k), k is number of unique words.

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& word : dictionary) {
            const int len = word.length();
            const string hash_val = word[0] + to_string(len - 2) + word[len - 1];
            lookup_[hash_val].emplace(word);
        }
    } 

    bool isUnique(string word) {
        const int len = word.length();
        const string hash_val = word[0] + to_string(len - 2) + word[len - 1];
        return lookup_[hash_val].empty() ||
               (lookup_[hash_val].count(word) == lookup_[hash_val].size());
    }
private:
    unordered_map<string, unordered_set<string>> lookup_;
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
