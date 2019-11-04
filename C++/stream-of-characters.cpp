// Time: ctor:  O(n)    , n is the total size of patterns
//       query: O(m + z), m is the total size of query string
//                      , z is the number of all matched strings
//                      , query time could be further improved to O(m) if we don't return all matched patterns
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

    vector<int> step(char letter) {
        while (node_ && !node_->children[letter - 'a']) {
            node_ = node_->suffix;
        }
        node_ = node_ ? node_->children[letter - 'a'] : root_;
        return getACNodeOutputs(node_);
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
                auto suffix = node->suffix;
                while (suffix && !suffix->children[c]) {
                    suffix = suffix->suffix;
                }
                child->suffix = suffix ? suffix->children[c] : root;
                child->output = !child->suffix->indices.empty() ?
                    child->suffix : child->suffix->output;
            }
        }
        
        return root;
    }
    
    vector<int> getACNodeOutputs(AhoNode *node) {  // Time:  O(z), in this question, it could be improved to O(1)
                                                   // if we only return a matched pattern without all matched ones
        vector<int> result;
        for (const auto& i : node_->indices) {
            result.emplace_back(i);
            // return result;
        }
        auto output = node_->output;
        while (output) {
            for (const auto& i : output->indices) {
                result.emplace_back(i);
                // return result;
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
    
    bool query(char letter) {  // O(m) times
        return !trie_.step(letter).empty();
    }

private:
    AhoTrie trie_;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
