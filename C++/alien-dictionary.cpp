// Time:  O(|V|+|E|) = O(26 + 26^2) = O(1)
// Space: O(|E|) = O(26^2) = O(1)

class Solution {
public:
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

    // Perform topological sort, return whether there is a cycle.
    bool topSortDFS(string *result, vector<bool> *visited,
                    vector<vector<bool>> *graph, const int root) {
        if ((*visited)[root]) {
            *result = "";
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

    string alienOrder(vector<string>& words) {
        string result;
        if (words.empty()) {
            return result;
        }
        if (words.size() == 1) {
            return words[0];
        }

        vector<vector<bool>> graph(26, vector<bool>(26));
        findDependency(words, &graph);
        findOrder(&graph, &result);
        return result;
    }
};
