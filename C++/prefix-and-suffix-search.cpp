// Time:  ctor:   O(w * l^2), w is the number of words, l is the word length on average
//        search: O(p + s)  , p is the length of the prefix, s is the length of the suffix,
// Space: O(t), t is the number of trie nodes

class WordFilter {
public:
    WordFilter(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].length(); ++j) {
                trie_.insert(words[i].substr(j) + SEPARATOR + words[i], i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return trie_.find(suffix + SEPARATOR + prefix);
    }

private:
    struct TrieNode {
        int weight;
        vector<TrieNode *> leaves;

        TrieNode() : weight(0), leaves(27) {}

        void insert(const string& s, const int weight) {
            auto* p = this;
            p->weight = weight;
            for (const auto& c : s) {
                if (!p->leaves[c - 'a']) {
                    p->leaves[c - 'a'] = new TrieNode;
                }
                p = p->leaves[c - 'a'];
                p->weight = weight;
            }
        }

        int find(const string& s) const {
            auto* p = this;
            for (const auto& c : s) {
                if (!p->leaves[c - 'a']) {
                    return -1;
                }
                p = p->leaves[c - 'a'];
            }
            return p->weight;
        }

        ~TrieNode() {
            for (auto& node : leaves) {
                if (node) {
                    delete node;
                }
            }
        }
    };
    const string SEPARATOR = "{";  // ascii code of 'z' + 1
    TrieNode trie_;
};

// Time:  ctor:   O(w * l), w is the number of words, l is the word length on average
//        search: O(p + s + max(m, n)), p is the length of the prefix, s is the length of the suffix,
//                                      m is the number of the prefix match, n is the number of the suffix match
// Space: O(w * l)
class WordFilter2 {
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
    TrieNode prefix_trie_, suffix_trie_;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
