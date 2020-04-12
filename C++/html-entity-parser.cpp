// Time:  O(n + m + z) = O(m), n is the total size of patterns
//                           , m is the total size of query string
//                           , z is the number of all matched strings
//                           , O(n) = O(1), O(z) = O(m) in this problem
// Space: O(t) = O(1), t is the total size of ac automata trie
//                   , O(t) = O(1) in this problem

struct AhoNode {
    unordered_map<char, AhoNode *> children;
    vector<int> indices;
    AhoNode *suffix;
    AhoNode *output;
    AhoNode() :
        suffix(nullptr),
        output(nullptr) {}
};

class AhoTrie {
public:
    AhoTrie(const vector<string>& patterns) : root_(createACTrie(patterns)) {
        node_ = createACSuffixAndOutputLinks(root_);
    }

    vector<int> step(char letter) {
        while (node_ && !node_->children[letter]) {
            node_ = node_->suffix;
        }
        node_ = node_ ? node_->children[letter] : root_;
        return getACNodeOutputs(node_);
    }

private:
    AhoNode *createACTrie(const vector<string>& patterns) {  // Time:  O(n), Space: O(t)
        auto root = new AhoNode();
        for (int i = 0; i < patterns.size(); ++i) {
            auto node = root;
            for (const auto& c : patterns[i]) {
                if (!node->children[c]) {
                    node->children[c] = new AhoNode();
                }
                node = node->children[c];
            }
            node->indices.emplace_back(i);
        }
        return root;
    }
    
    AhoNode *createACSuffixAndOutputLinks(AhoNode *root) {  // Time:  O(n), Space: O(t)
        queue<AhoNode *> q;
        for (const auto& kvp : root->children) {
            const auto& node = kvp.second;
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
    string entityParser(string text) {
        static const vector<string> patterns = {"&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"};
        static const vector<string> chars = {"\"", "'", "&", ">", "<", "/"};
        AhoTrie trie(patterns);
        vector<pair<int, int>> positions;
        for (int i = 0; i < text.length(); ++i) {
            for (const auto& j : trie.step(text[i])) {
                positions.emplace_back(i - patterns[j].length() + 1, j);
            }
        }
        string result;
        for (int i = 0, j = 0; i != text.length();) {
            if (j == positions.size() || i != positions[j].first) {                    
                result.push_back(text[i]);
                ++i;
            } else {
                result += chars[positions[j].second];
                i += patterns[positions[j].second].length();
                ++j;
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    string entityParser(string text) {
        static const vector<string> patterns = {"&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"};
        static const vector<string> chars = {"\"", "'", "&", ">", "<", "/"};
        string result;
        for (int i = 0; i != text.length();) {
            if (text[i] != '&') {                    
                result.push_back(text[i]);
                ++i;
            } else {
                bool is_found = false;
                for (int j = 0; j < patterns.size(); ++j) {
                    if (patterns[j] == text.substr(i, patterns[j].length())) {
                        is_found = true;
                        result += chars[j];
                        i += patterns[j].length();
                        break;
                    }
                }
                if (!is_found) {
                    result.push_back(text[i]);
                    ++i;
                }
            }
        }
        return result;
    }
};
