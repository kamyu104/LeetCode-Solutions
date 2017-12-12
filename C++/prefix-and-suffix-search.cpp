// Time:  ctor:   O(w * l^2), w is the number of words, l is the word length on average
//        search: O(p + s)  , p is the length of the prefix, s is the length of the suffix,
// Space: O(t), t is the number of trie nodes

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
    const string SEPARATOR = "{";  // ascii code of 'z' + 1
    TrieNode trie_;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
