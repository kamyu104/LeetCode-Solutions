// Time:  O(|V|+|E|) = O(26 + 26^2) = O(1)
// Space: O(|V|+|E|) = O(26 + 26^2) = O(1)

// BFS solution.
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> nodes;
        unordered_map<char, unordered_set<char>> in_degree, out_degree;
        queue<char> zero_in_degree_queue;
        for (const auto& word : words) {
            for (char c : word) {
                nodes.emplace(c);
            }
        }
        for (int i = 1; i < words.size(); ++i) {
            findEdges(words[i - 1], words[i], &in_degree, &out_degree);
        }
        for (const auto& node : nodes) {
            if (in_degree.find(node) == in_degree.end()) {
                zero_in_degree_queue.emplace(node);
            }
        }

        // BFS
        string result;
        while (!zero_in_degree_queue.empty()) {
            const auto& precedence = zero_in_degree_queue.front();
            zero_in_degree_queue.pop();
            result.push_back(precedence);
            
            if (out_degree.find(precedence) != out_degree.end()) {
                for (const auto& c : out_degree[precedence]) {
                    in_degree[c].erase(precedence);
                    if (in_degree[c].empty()) {
                        zero_in_degree_queue.emplace(c);
                    }
                }
                out_degree.erase(precedence);
            }
        }
        
        if (!out_degree.empty()) {
            return "";
        }
        
        return result;
    }

private:
    // Construct the graph.
    void findEdges(const string &word1, const string &word2,
                   unordered_map<char, unordered_set<char>> *in_degree,
                   unordered_map<char, unordered_set<char>> *out_degree) {
        int len = min(word1.length(), word2.length());
        for (int i = 0; i < len; ++i) {
            if (word1[i] != word2[i]) {
                (*in_degree)[word2[i]].emplace(word1[i]);
                (*out_degree)[word1[i]].emplace(word2[i]);
                break;
            }
        }
    }
};

// DFS solution.
class Solution2 {
public:
    string alienOrder(vector<string>& words) {
        // Find ancestors of each node by DFS.
        unordered_set<char> nodes;
        unordered_map<char, vector<char>> ancestors;
        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i]) {
                nodes.emplace(c);
            }
            if (i > 0) {
                findEdges(words[i - 1], words[i], &ancestors);
            }
        }

        // Output topological order by DFS.
        string result;
        unordered_map<char, char> visited;
        for (const auto& node : nodes) {
            if (topSortDFS(node, node, &ancestors, &visited, &result)) {
                return "";
            }
        }
        
        return result;
    }

private:
    // Construct the graph.
    void findEdges(const string &word1, const string &word2,
                   unordered_map<char, vector<char>> *ancestors) {
        int len = min(word1.length(), word2.length());
        for (int i = 0; i < len; ++i) {
            if (word1[i] != word2[i]) {
                (*ancestors)[word2[i]].emplace_back(word1[i]);
                break;
            }
        }
    }

    // Topological sort, return whether there is a cycle.
    bool topSortDFS(const char& root,
                    const char& node,
                    unordered_map<char, vector<char>> *ancestors,
                    unordered_map<char, char> *visited,
                    string *result) {
        if (visited->emplace(make_pair(node, root)).second) {
            for (auto& ancestor: (*ancestors)[node]) {
                if (topSortDFS(root, ancestor, ancestors, visited, result)) {
                    return true;
                }
            }
            result->push_back(node);
        } else if ((*visited)[node] == root) {
            // Visited from the same root in the DFS path.
            // So it is cyclic.
            return true;
        }
        return false;
    } 
};

// Adjacency matrix method.
class Solution2 {
public:
    string alienOrder(vector<string>& words) {
        string result;
        vector<vector<bool>> graph(26, vector<bool>(26));
        findDependency(words, &graph);
        findOrder(&graph, &result);
        return result;
    }

private:
    void findEdges(const string &word1, const string &word2, vector<vector<bool>> *graph) {
        int len = min(word1.length(), word2.length());
        for (int i = 0; i < len; ++i) {
            if (word1[i] != word2[i]) {
                (*graph)[word1[i] - 'a'][word2[i] - 'a'] = true;
                break;
            }
        }
    }

    // Construct the graph.
    void findDependency(const vector<string>& words, vector<vector<bool>> *graph) {
        for (const auto& c : words[0]) {
            (*graph)[c - 'a'][c - 'a'] = true;
        }
        for (int i = 1; i < words.size(); ++i) {
            for (const auto& c : words[i]) {
                (*graph)[c - 'a'] [c - 'a'] = true;
            }
            findEdges(words[i - 1], words[i], graph);
        }
    }

    // Topological sort, return whether there is a cycle.
    bool topSortDFS(string *result, vector<bool> *visited,
                    vector<vector<bool>> *graph, const int root) {
        if ((*visited)[root]) {
            result->clear();
            return true;
        }
        (*visited)[root] = true;
        for (int i = 0; i < 26; ++i) {
            if (i != root && (*graph)[root][i]) {
                if (topSortDFS(result, visited, graph, i)) {
                    return true;
                }
            }
        }
        (*graph)[root][root] = false;
        result->push_back(root + 'a');
        return false;
    }  

    void findOrder(vector<vector<bool>> *graph, string *result) {
        for (int i = 0; i < 26; ++i) {
            // Find a root node.
            bool root_node = (*graph)[i][i];
            if ((*graph)[i][i]) {
                for (int j = 0; j < 26; ++j) {
                    if (j != i && (*graph)[j][i]) {
                        root_node = false;
                        break;
                    }
                }
            }
            if (root_node) {
                string reversed_order = "";
                vector<bool> visited(26, false);
                if (topSortDFS(&reversed_order, &visited, graph, i)) {
                    result->clear();
                    return;
                } else {
                    result->append(reversed_order);
                }
            }
        }

        // If there is any unvisited node, return "".
        for (int i = 0; i < 26; ++i) {
            if ((*graph)[i][i]) {
                result->clear();
                return;
            }
        }
        // The order should be reversed.
        reverse(result->begin(), result->end());
    }
};
