// Time: ctor:   O(w * l), w is the number of words, l is the word length on average
//       search: O(p + s + m + n), p is the length of the prefix, s is the length of the suffix,
//                                 m is the number of the prefix match, n is the number of the suffix match
// Space: O(w * l)

struct TrieNode {
    vector<int> words; // index of words
    vector<TrieNode *> leaves;

    TrieNode() : leaves(26) {}

    void insert(const string& s, const int i) {
        auto* p = this;
        p->words.emplace_back(i);
        for (const auto& c : s) {
            if (!p->leaves[c - 'a']) {
                p->leaves[c - 'a'] = new TrieNode;
            }
            p = p->leaves[c - 'a'];
            p->words.emplace_back(i);
        }
    }
    
    const vector<int>& find(const string& s) const {
        auto* p = this;
        for (const auto& c : s) {
            if (!p->leaves[c - 'a']) {
                static const vector<int> empty;
                return empty;
            }
            p = p->leaves[c - 'a'];
        }
        return p->words;
    }

    ~TrieNode() {
        for (auto& node : leaves) {
            if (node) {
                delete node;
            }
        }
    }
};

class WordFilter {
public:
    WordFilter(vector<string> words) {
        for (int i = words.size() - 1; i >= 0; --i) {
            auto word = words[i];
            prefix_trie_.insert(word, i);
            reverse(word.begin(), word.end());
            suffix_trie_.insert(word, i);
        }
    }
    
    int f(string prefix, string suffix) {
        const auto& prefix_match = prefix_trie_.find(prefix);
        reverse(suffix.begin(), suffix.end());
        const auto& suffix_match = suffix_trie_.find(suffix);
        int i = 0, j = 0;
        while (i != prefix_match.size() && j != suffix_match.size()) {
            if (prefix_match[i] == suffix_match[j]) {
                return prefix_match[i];
            } else if (prefix_match[i] > suffix_match[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return -1;
    }
    
private:
    TrieNode prefix_trie_, suffix_trie_;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
 
