// Time:  ctor:  O(n + p^2), n is the total size of patterns
//                         , p is the count of patterns
//        query: O(m + z), m is the total size of query string
//                       , z is the number of all matched strings 
// Space: O(t + p^2), t is the total size of ac automata trie

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
    AhoTrie(const vector<string>& patterns) {
        root_ = CreateACTrie(patterns);
        node_ = CreateACSuffixAndOutputLinks(root_);
    }

    bool query(char letter) {
        while (node_ && !node_->children[letter - 'a']) {
            node_ = node_->suffix;
        }
        if (!node_) {
            node_ = root_;
            return false;
        }
    
        node_ = node_->children[letter - 'a'];
        vector<int> result = node_->outputs;
        return !result.empty();
    }

private:
    AhoNode *CreateACTrie(const vector<string>& patterns) {  // Time:  O(n), Space: O(t)
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
    
    AhoNode *CreateACSuffixAndOutputLinks(AhoNode *root) {  // Time:  O(n + p^2), Space: O(t + p^2)
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
                copy (child->suffix->outputs.cbegin(),
                      child->suffix->outputs.cend(),
                      back_inserter(child->outputs));  // Time: O(p^2)
            }
        }
        
        return root;
    }
    
    AhoNode *root_;
    AhoNode *node_;
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) : trie_(words) {
    }
    
    bool query(char letter) {
        return trie_.query(letter);
    }

private:
    AhoTrie trie_;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
