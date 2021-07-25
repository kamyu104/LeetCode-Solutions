// Time:  O(m * nlogn + l * t^2), m is the max number of folders in a path,
//                              , n is the number of paths
//                              , l is the max length of folder name
//                              , t is the size of trie
// Space: O(l * t^2)

class Solution {
private:
    class TrieNode { 
    public:
        bool deleted = false;
        map<string, unique_ptr<TrieNode>> leaves;

        void Insert(const vector<string>& s) {
            auto p = this;
            for (const auto& c : s) {
                if (!p->leaves.count(c)) {
                    p->leaves[c] = make_unique<TrieNode>();
                }
                p = p->leaves[c].get();
            }
        }
    };
  
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        auto trie = make_unique<TrieNode>();
        for (const auto& path : paths) {
            trie->Insert(path);
        }
        unordered_map<string, TrieNode*> lookup;
        mark(trie.get(), &lookup);
        vector<vector<string>> result;
        vector<string> path;
        sweep(trie.get(), &path, &result);
        return result;
    }

private:
    string mark(TrieNode *node, unordered_map<string, TrieNode*> *lookup) {
        string serialized_tree = "(";
        for (const auto& [subfolder, child] : node->leaves) {
            serialized_tree += subfolder + mark(child.get(), lookup);
        }
        serialized_tree += ")";
        if (serialized_tree != "()") {
            if (lookup->count(serialized_tree)) {
                (*lookup)[serialized_tree]->deleted = true;
                node->deleted = true;
            } else {
                (*lookup)[serialized_tree] = node;
            }
        }
        return serialized_tree;
    }

    void sweep(TrieNode *node, vector<string> *path, vector<vector<string>> *result) {
        if (!empty(*path)) {
            result->emplace_back(*path);
        }
        for (const auto& [subfolder, child] : node->leaves) {
            if (child->deleted) {
                continue;
            }
            path->emplace_back(subfolder);
            sweep(child.get(), path, result);
            path->pop_back();
        }
    }
};
