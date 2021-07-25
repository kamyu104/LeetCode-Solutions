// Time:  O(n * m * l + tlogt + l * t), m is the max number of folders in a path,
//                                    , n is the number of paths
//                                    , l is the max length of folder name
//                                    , t is the size of trie
// Space: O(l * t)

class Solution {
private:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

    template<typename T>
    struct VectorPairHash {
        size_t operator()(const std::vector<pair<T, T>>& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= PairHash<T>{}(i)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };

    class TrieNode { 
    public:
        bool deleted = false;
        unordered_map<int, unique_ptr<TrieNode>> leaves;

        void Insert(const vector<string>& s,
                    unordered_map<string, int> *folder_ids,
                    unordered_map<int, string> *names) {
            auto p = this;
            for (const auto& c : s) {
                if (!folder_ids->count(c)) {
                    (*folder_ids)[c] = size(*folder_ids);
                    (*names)[(*folder_ids)[c]] = c;
                }
                const auto folder_id = (*folder_ids)[c];
                if (!p->leaves.count(folder_id)) {
                    p->leaves[folder_id] = make_unique<TrieNode>();
                }
                p = p->leaves[folder_id].get();
            }
        }
    };
  
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        auto trie = make_unique<TrieNode>();
        unordered_map<string, int> folder_ids;
        unordered_map<int, string> names;
        for (const auto& path : paths) {
            trie->Insert(path, &folder_ids, &names);
        }
        unordered_map<int, TrieNode*> lookup;
        unordered_map<vector<pair<int, int>>, int, VectorPairHash<int>> node_ids;
        mark(trie.get(), &lookup, &node_ids);
        vector<vector<string>> result;
        vector<int> path;
        sweep(trie.get(), names, &path, &result);
        return result;
    }

private:
    int mark(TrieNode *node,
             unordered_map<int, TrieNode*> *lookup,
             unordered_map<vector<pair<int, int>>, int, VectorPairHash<int>> *node_ids) {
        vector<pair<int, int>> id_pairs;
        for (const auto& [subfolder_id, child] : node->leaves) {
            id_pairs.emplace_back(subfolder_id, mark(child.get(), lookup, node_ids));
        }
        sort(begin(id_pairs), end(id_pairs));
        if (!node_ids->count(id_pairs)) {
            (*node_ids)[id_pairs] = size(*node_ids);
        }
        int node_id = (*node_ids)[id_pairs];
        if (node_id) {
            if (lookup->count(node_id)) {
                (*lookup)[node_id]->deleted = true;
                node->deleted = true;
            } else {
                (*lookup)[node_id] = node;
            }
        }
        return node_id;
    }

    void sweep(TrieNode *node,
               const unordered_map<int, string>& names,
               vector<int> *path,
               vector<vector<string>> *result) {
        if (!empty(*path)) {
            result->emplace_back();
            transform(cbegin(*path), cend(*path), back_inserter(result->back()),
                      [&names](const auto& i) {
                          return names.at(i);
                      });
        }
        for (const auto& [subfolder_id, child] : node->leaves) {
            if (child->deleted) {
                continue;
            }
            path->emplace_back(subfolder_id);
            sweep(child.get(), names, path, result);
            path->pop_back();
        }
    }
};

// Time:  O(n * m * l + l * tlogt + l * t^2), m is the max number of folders in a path,
//                                          , n is the number of paths
//                                          , l is the max length of folder name
//                                          , t is the size of trie
// Space: O(l * t^2)
class Solution2 {
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
