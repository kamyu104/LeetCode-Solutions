// Time:  O(n) for constructor, n is number of words in the dictionary. 
//        O(1) for lookup
// Space: O(k), k is number of unique words.

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& word : dictionary) {
            const string hash_val = word.front() + to_string(word.length()) + word.back();
            lookup_[hash_val].emplace(word);
        }
    } 

    bool isUnique(string word) {
        const string hash_val = word.front() + to_string(word.length()) + word.back();
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
