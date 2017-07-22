// Time:  O(s + n), s is the length of the prefix,
//                  n is the number of the subtree nodes of trie given with the prefix
// Space: O(t), t is the size of trie

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < sentences.size(); ++i) {
            trie_.insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        vector<string> result;
        if (c == '#') {
            trie_.insert(cur_sent_, 1);
            cur_sent_.clear();
        } else {
            cur_sent_.push_back(c);
            result = trie_.lookup(cur_sent_);
        }
        return result;
    }

private:
    class TrieNode {
    public:
        using P = pair<int, string>;
        static const int TOP_COUNT = 3;
        class Compare {
        public:
            bool operator()(const P& p1, const P& p2) {
                return p1.first != p2.first ? p1.first > p2.first : p1.second < p2.second;
            }
        };

        TrieNode() : times_(0) {
        }
        
        ~TrieNode() {
            for (auto& kv : leaves_) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }

        // Time:  O(s)
        void insert(const string& s, int times) {
            auto* p = this;
            for (const auto& c : s) {
                if (!p->leaves_.count(c)) {
                    p->leaves_[c] = new TrieNode;
                }
                p = p->leaves_[c];
            }
            p->times_ += times;
        }
        
        // Time:  O(s + n)
        vector<string> lookup(string& s) {
            auto* p = this;
            for (const auto& c : s) {
                if (!p->leaves_.count(c)) {
                    return {};
                }
                p = p->leaves_[c];
            }
            priority_queue<P, vector<P>, Compare> min_heap;
            traverseHelper(s, p, &min_heap);
            vector<string> result;
            while (!min_heap.empty()) {
                result.emplace_back(min_heap.top().second);
                min_heap.pop();
            }
            reverse(result.begin(), result.end());
            return result;
        }

        private:
        // Time:  O(n)
        void traverseHelper(string& s, TrieNode *t, priority_queue<P, vector<P>, Compare> *min_heap) {
            if (t->times_ > 0) {
                min_heap->emplace(t->times_, s);
                if (min_heap->size() == TOP_COUNT + 1) {
                    min_heap->pop();
                }
            }

            for (auto i = 'a'; i <= 'z'; ++i) {
                if (t->leaves_.count(i)) {
                    s.push_back(i);
                    traverseHelper(s, t->leaves_[i], min_heap);
                    s.pop_back();
                }
            }
            if (t->leaves_.count(' ')) {
                s.push_back(' ');
                traverseHelper(s, t->leaves_[' '], min_heap);
                s.pop_back();
            }
        }
        
        unordered_map<char, TrieNode *> leaves_;
        int times_;
    };

    TrieNode trie_;
    string cur_sent_;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */