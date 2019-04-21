// Time: ctor:  O(n)    , n is the total size of patterns
//       query: O(m + z), m is the total size of query string
//                      , z is the number of all matched strings 
// Space: O(t), t is the total size of ac automata trie
//            , space could be further improved by DAT (double-array trie)

// Aho–Corasick automata
// reference:
// 1. http://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Small02.pdf
// 2. http://algo.pw/algo/64/python

struct AhoNode {
    vector<AhoNode *> children;
    vector<int> indices;
    AhoNode *suffix;
    AhoNode *output;
    AhoNode() :
        children(26, nullptr),
        suffix(nullptr),
        output(nullptr) {}
};

class AhoTrie {
public:
    AhoTrie(const vector<string>& patterns) : root_(createACTrie(patterns)) {
        node_ = createACSuffixAndOutputLinks(root_);
    }

    bool step(char letter) {
        while (node_ && !node_->children[letter - 'a']) {
            node_ = node_->suffix;
        }
        if (!node_) {
            node_ = root_;
            return false;
        }
    
        
        node_ = node_->children[letter - 'a'];
        const auto& result = getACNodeOutputs(node_);
        return !result.empty();
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
            node->indices.emplace_back(i);
        }
        return root;
    }
    
    AhoNode *createACSuffixAndOutputLinks(AhoNode *root) {  // Time:  O(n), Space: O(t)
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
                auto fail = node->suffix;
                while (fail && !fail->children[c]) {
                    fail = fail->suffix;
                }
                child->suffix = fail ? fail->children[c] : root;
                child->output = !child->suffix->indices.empty() ?
                    child->suffix : child->suffix->output;
            }
        }
        
        return root;
    }
    
    vector<int> getACNodeOutputs(AhoNode *node) {
        vector<int> result;
        for (const auto& i : node_->indices) {
            result.emplace_back(i);
        }
        auto output = node_->output;
        while (output) {
            for (const auto& i : output->indices) {
                result.emplace_back(i);
            }
            output = output->output;
        }
        return result;
    }
    
    AhoNode * const root_;
    AhoNode *node_;
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) : trie_(words) {
    }
    
    bool query(char letter) {
        return trie_.step(letter);
    }

private:
    AhoTrie trie_;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
