// Time:  O(p^2), p is the length of the prefix
// Space: O(p * t), t is the number of nodes of trie

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) : cur_node_(&trie_) {
        for (int i = 0; i < sentences.size(); ++i) {
            sentence_to_count_[sentences[i]] = times[i];
            trie_.insert(sentences[i], sentence_to_count_[sentences[i]]);
        }
    }
    
    vector<string> input(char c) {
        vector<string> result;
        if (c == '#') {
            ++sentence_to_count_[search_];
            trie_.insert(search_, sentence_to_count_[search_]);
            cur_node_ = &trie_;
            search_.clear();
        } else {
            search_.push_back(c);
            if (cur_node_) {
                if (!cur_node_->leaves_.count(c)) {
                    cur_node_ = nullptr;
                    return {};
                }
                cur_node_ = cur_node_->leaves_[c];
                for (const auto& p : cur_node_->infos_) {
                    result.emplace_back(p.second);
                }
            }   
        }
        return result;
    }

private:
    class TrieNode {
    public:
        static const int TOP_COUNT = 3;

        ~TrieNode() {
            for (auto& kv : leaves_) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }

        // Time:  O(s)
        void insert(const string& s, int times) {
            auto* cur = this;
            cur->add_info(s, times);
            for (const auto& c : s) {
                if (!cur->leaves_.count(c)) {
                    cur->leaves_[c] = new TrieNode;
                }
                cur = cur->leaves_[c];
                cur->add_info(s, times);
            }
        }
        
        // Time:  O(1)
        void add_info(const string& s, int times) {
            auto it = find_if(infos_.begin(), infos_.end(),
                         [&s, &times](const pair<int, string>& p){ return p.second == s;} );
            if (it != infos_.end()) {
                it->first = -times;
            } else {
                infos_.emplace_back(-times, s);
            }
            sort(infos_.begin(), infos_.end());
            if (infos_.size() > TOP_COUNT) {
                infos_.pop_back();
            }
        }
        
        vector<pair<int, string>> infos_;
        unordered_map<char, TrieNode *> leaves_;
    };

    TrieNode trie_;
    TrieNode *cur_node_;
    string search_;
    unordered_map<string, int> sentence_to_count_;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */