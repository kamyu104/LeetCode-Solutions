// Time:  O(n) for constructor, n is number of words in the dictionary. 
//        O(1) for lookup
// Space: O(k), k is number of unique words.

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& word : dictionary) {
            const string hash_word = hash(word);
            lookup_[hash_word].emplace(word);
        }
    } 

    bool isUnique(string word) {
        const string hash_word = hash(word);
        return lookup_[hash_word].empty() ||
               (lookup_[hash_word].count(word) == lookup_[hash_word].size());
    }

private:
    unordered_map<string, unordered_set<string>> lookup_;

    string hash(const string& word) {
        return word.front() + to_string(word.length()) + word.back();;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
