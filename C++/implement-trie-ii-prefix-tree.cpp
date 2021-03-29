// Time:  ctor:         O(1)
//        insert:       O(n)
//        count_word:   O(n)
//        count_prefix: O(n)
//        erase:        O(n)
// Space: O(t), t is the number of nodes in trie

class TrieNode { 
public:
    TrieNode() : children(26) {}
    vector<unique_ptr<TrieNode>> children;
    int pcnt = 0;
    int cnt = 0;
};

class Trie {
public:
    Trie() {
        trie_ = make_unique<TrieNode>();
    }
    
    void insert(string word) {
        auto curr = trie_.get();
        ++curr->pcnt;
        for (const auto& c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = make_unique<TrieNode>();
            }
            curr = curr->children[c - 'a'].get();
            ++curr->pcnt;
        }
        ++curr->cnt;
    }
    
    int countWordsEqualTo(string word) {
        auto curr = trie_.get();
        for (const auto& c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                return 0;
            }
            curr = curr->children[c - 'a'].get();
        }
        return curr->cnt;
    }
    
    int countWordsStartingWith(string prefix) {
        auto curr = trie_.get();
        for (const auto& c : prefix) {
            if (curr->children[c - 'a'] == nullptr) {
                return 0;
            }
            curr = curr->children[c - 'a'].get();
        }
        return curr->pcnt;
    }
    
    void erase(string word) {
        int cnt = countWordsEqualTo(word);
        if (!cnt) {
            return;
        }
        auto curr = trie_.get();
        --curr->pcnt;
        for (const auto& c : word) {
            if (curr->children[c - 'a']->pcnt == 1) {
                curr->children[c - 'a'].reset();  // delete all unused nodes
                return;
            }
            curr = curr->children[c - 'a'].get();
            --curr->pcnt;
        }
        --curr->cnt;
    }

private:
    unique_ptr<TrieNode> trie_;
};
