// Time:  O(n), n is the length of key
// Space: O(t), t is the number of nodes in trie

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        trie_.Insert(key, val);
    }
    
    int sum(string prefix) {
        return trie_.GetCount(prefix);
    }

private:
    struct TrieNode {
        bool isString = false;
        int count = 0;
        int val = 0;
        unordered_map<char, TrieNode *> leaves;
        
        void Insert(const string& s, const int val) {
            const auto delta = val - GetVal(s);
            auto* p = this;
            for (const auto& c : s) {
                if (p->leaves.find(c) == p->leaves.cend()) {
                    p->leaves[c] = new TrieNode;
                }
                p = p->leaves[c];
                p->count += delta;
            }
            p->val = val;
            p->isString = true;
        }

        int GetVal(const string& s) const {
            auto* p = this;
            for (const auto& c : s) {
                if (p->leaves.find(c) == p->leaves.cend()) {
                    return 0;
                }
                p = p->leaves.at(c);
            }
            return p->isString ? p->val : 0;
        }

        int GetCount(const string& s) const {
            auto* p = this;
            for (const auto& c : s) {
                if (p->leaves.find(c) == p->leaves.cend()) {
                    return 0;
                }
                p = p->leaves.at(c);
            }
            return p->count;
        }

        ~TrieNode() {
            for (auto& kv : leaves) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }
    };
    TrieNode trie_;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
 
