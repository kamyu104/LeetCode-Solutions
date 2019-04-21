// Time:  ctor:  O(n + p^2), n is the total size of patterns
//                         , p is the number of patterns
//        query: O(m + z), m is the total size of query string
//                       , z is the number of all matched strings 
//                       , query time would be O(m) if we don't use all the matched patterns
// Space: O(t + p^2), t is the total size of ac automata trie
//                  , space could be further improved by DAT (double-array trie)

// Aho–Corasick automata
// reference:
// 1. http://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Small02.pdf
// 2. http://algo.pw/algo/64/python

struct AhoNode {
    vector<AhoNode *> children;
    AhoNode *suffix;
    vector<int> outputs;
    AhoNode() :
        children(26, nullptr),
        suffix(nullptr)  {}
};

class AhoTrie {
public:
    AhoTrie(const vector<string>& patterns) : root_(createACTrie(patterns)) {
        node_ = createACSuffixAndOutputLinks(root_);
    }

    vector<int> *step(char letter) {
        while (node_ && !node_->children[letter - 'a']) {
            node_ = node_->suffix;
        }
        node_ = node_ ? node_->children[letter - 'a'] : root_;
        return &node_->outputs;  // Time:  O(z), it would be O(1) if we don't use all the matched patterns
    }

private:
    AhoNode *createACTrie(const vector<string>& patterns) {  // Time:  O(n), Space: O(t)
        auto root = new AhoNode();
        for (int i = 0; i < patterns.size(); ++i) {
            auto node = root;
            for (const auto& c : patterns[i]) {
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = new AhoNode();
                }
                node = node->children[c - 'a'];
            }
            node->outputs.emplace_back(i);
        }
        return root;
    }
    
    AhoNode *createACSuffixAndOutputLinks(AhoNode *root) {  // Time:  O(n + p^2), Space: O(t + p^2)
        queue<AhoNode *> q;
        for (auto node : root->children) {
            if (!node) {
                continue;
            }
            q.emplace(node);
            node->suffix = root;
        }
                
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            for (int c = 0; c < node->children.size(); ++c) {
                if (!node->children[c]) {
                    continue;
                }
                auto child = node->children[c];
                q.emplace(child);
                auto suffix = node->suffix;
                while (suffix && !suffix->children[c]) {
                    suffix = suffix->suffix;
                }
                child->suffix = suffix ? suffix->children[c] : root;
                copy(child->suffix->outputs.cbegin(),
                     child->suffix->outputs.cend(),
                     back_inserter(child->outputs));  // Time: O(p^2)
            }
        }
        
        return root;
    }
    
    AhoNode * const root_;
    AhoNode *node_;
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) : trie_(words) {
    }
    
    bool query(char letter) {  // O(m) times
        return !trie_.step(letter)->empty();
    }

private:
    AhoTrie trie_;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
