// Time:  O(n * l + m), n is the number of patterns
//                    , l is the max length of patterns
//                    , m is the length of word     
// Space: O(t)        , t is the total size of ac automata trie

struct AhoNode {
    vector<unique_ptr<AhoNode>> children;
    vector<int> indices;
    AhoNode *suffix;
    AhoNode *output;
    AhoNode()
      : children(26)
      , suffix(nullptr)
      , output(nullptr) {}
};

class AhoTrie {
public:
    AhoTrie(const vector<string>& patterns) : root_(createACTrie(patterns)) {
        node_ = createACSuffixAndOutputLinks(root_.get());
    }

    vector<int> step(char letter) {
        while (node_ && !node_->children[letter - 'a']) {
            node_ = node_->suffix;
        }
        node_ = node_ ? node_->children[letter - 'a'].get() : root_.get();
        return getACNodeOutputs(node_);
    }
    
    void reset() {
        node_ = root_.get();
    }

private:
    unique_ptr<AhoNode> createACTrie(const vector<string>& patterns) {  // Time:  O(n * l), Space: O(t)
        auto root = make_unique<AhoNode>();
        for (int i = 0; i < patterns.size(); ++i) {
            auto node = root.get();
            for (const auto& c : patterns[i]) {
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = make_unique<AhoNode>();
                }
                node = node->children[c - 'a'].get();
            }
            node->indices.emplace_back(i);
        }
        return root;
    }
    
    AhoNode *createACSuffixAndOutputLinks(AhoNode *root) {  // Time: O(n * l), Space: O(t)
        queue<AhoNode *> q;
        for (int c = 0; c < size(root->children); ++c) {
            auto node = root->children[c].get();
            if (!node) {
                continue;
            }
            q.emplace(node);
            node->suffix = root;
        }
                
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            for (int c = 0; c < size(node->children); ++c) {
                if (!node->children[c]) {
                    continue;
                }
                auto child = node->children[c].get();
                q.emplace(child);
                auto suffix = node->suffix;
                while (suffix && !suffix->children[c]) {
                    suffix = suffix->suffix;
                }
                child->suffix = suffix ? suffix->children[c].get() : root;
                child->output = !child->suffix->indices.empty() ?
                    child->suffix : child->suffix->output;
            }
        }
        
        return root;
    }
    
    vector<int> getACNodeOutputs(AhoNode *node) {  // Total Time: O(n), modified
        vector<int> result;
        if (!lookup_.count(node)) {  // modified
            lookup_.emplace(node);  // modified
            for (const auto& i : node_->indices) {
                result.emplace_back(i);
            }
            auto output = node_->output;
            while (output && !lookup_.count(output)) {  // modified
                lookup_.emplace(output);
                for (const auto& i : output->indices) {  // modified
                    result.emplace_back(i);
                }
                output = output->output;
            }
        }
        return result;
    }
    
    unique_ptr<AhoNode> root_;
    AhoNode *node_;
    unordered_set<AhoNode *> lookup_;  // modified
};

// ac automata solution
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        auto trie = AhoTrie(patterns);
        return accumulate(cbegin(word), cend(word), 0,
                          [&trie](int total, const auto& x) {
                              return total + size(trie.step(x));
                          });
    }
};

// Time:  O(n * (l + m)), n is the number of patterns
//                      , l is the max length of patterns
//                      , m is the length of word
// Space: O(l)
// kmp solution
class Solution2 {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        return accumulate(cbegin(patterns), cend(patterns), 0,
                          [this, &word](int total, const auto& x) {
                              return total + static_cast<int>(kmp(word, x) != -1);
                          });
    }

private:
    int kmp(const string& text, const string& pattern) {
        if (pattern.empty()) {
            return 0;
        }
        const auto& prefix = getPrefix(pattern);
        if (text.length() < pattern.length()) {
            return -1;
        }
        int j = -1;
        for (int i = 0; i < text.length(); ++i) {
            while (j != -1 && pattern[j + 1] != text[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i]) {
                ++j;
            }
            if (j + 1 == pattern.length()) {
                return i - j;
            }
        }
        return -1;
    }

    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};

// Time:  O(n * m * l), n is the number of patterns
//                    , l is the max length of patterns
//                    , m is the length of word
// Space: O(1)
// built-in solution
class Solution3 {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        return accumulate(cbegin(patterns), cend(patterns), 0,
                          [&word](int total, const auto& x) {
                              return total + static_cast<int>(word.find(x) != string::npos);
                          });
    }
};
