// Time:  O(n + m + z) = O(n), n is the total size of patterns
//                           , m is the total size of query string
//                           , z is the number of all matched strings
//                           , O(n) = O(m) = O(z) in this problem
// Space: O(t), t is the total size of ac automata trie

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
    
    void reset() {
        node_ = root_;
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
    
    vector<int> getACNodeOutputs(AhoNode *node) {  // Time:  O(z)
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

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        AhoTrie trie(words);
        unordered_set<int> lookup;
        for (int i = 0; i < words.size(); ++i) {
            trie.reset();
            for (const auto& c : words[i]) {
                for (const auto& j : trie.step(c)) {
                    if (j != i) {
                        lookup.emplace(j);
                    }
                }
            }
        }
        vector<string> result;
        for (const auto& i : lookup) {
            result.emplace_back(words[i]);
        }
        return result;
    }
};

// Time:  O(n^2 * l), n is the number of strings
// Space: O(l)      , l is the max length of strings
class Solution2 {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        for (int i = 0; i < words.size(); ++i) {
            const auto& prefix = getPrefix(words[i]);
            for (int j = 0; j < words.size(); ++j) {
                if (i != j && kmp(words[j], words[i], prefix) != -1) {
                    result.emplace_back(words[i]);
                    break;
                }
            }
            
        }
        return result;
    }

private:
    int kmp(const string& text, const string& pattern, const vector<int>& prefix) {
        if (pattern.empty()) {
            return 0;
        }
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

// Time:  O(n^2 * l^2), n is the number of strings
// Space: O(1)        , l is the max length of strings
class Solution3 {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    result.emplace_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};
