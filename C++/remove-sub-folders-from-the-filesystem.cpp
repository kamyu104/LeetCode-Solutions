// Time:  O(n), n is the total sum of the lengths of folder names
// Space: O(t), t is the number of nodes in trie

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        TrieNode trie;
        for (const auto& s : folder) {
            trie.Insert(split(s, '/'));
        }
        vector<string> result;
        vector<string> path;
        dfs(&trie, &path, &result);
        return result;
    }

private:
    struct TrieNode {
        bool is_end = false;
        unordered_map<string, TrieNode *> leaves;

        void Insert(const vector<string>& s) {
            auto* p = this;
            for (const auto& c : s) {
                if (c.empty()) {
                    continue;
                }
                if (!p->leaves.count(c)) {
                    p->leaves[c] = new TrieNode;
                }
                p = p->leaves[c];
            }
            p->is_end = true;
        }

        ~TrieNode() {
            for (auto& kv : leaves) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }
    };
    
    void dfs(TrieNode *curr, vector<string> *path, vector<string> *result) {
        if (curr->is_end) {
            result->emplace_back(join(*path, '/'));
            return;
        }
        for (const auto& kvp : curr->leaves) {
            path->emplace_back(kvp.first);
            dfs(kvp.second, path, result);
            path->pop_back();
        }
    }

    vector<string> split(const string& s, const char delim) {
        vector<string> result;
        auto end = string::npos;
        do {
            const auto& start = end + 1;
            end = s.find(delim, start);
            result.emplace_back(s.substr(start, end - start));
        } while (end != string::npos); 
        return result;
    }

    string join(const vector<string>& names, const char delim) {
        string result;
        for (const auto& name : names) {
            result.push_back('/');
            result += name;
        }
        return result;
    }
};
