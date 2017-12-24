// Time:  O(n *k^n)
// Space: O(n *k^n)

class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> lookup;
        string result;
        string node(n - 1, '0');
        dfs(k, node, &lookup, &result);
        result += string(n - 1, '0');
        return result;
    }

private:
    void dfs(int k, const string& node, unordered_set<string> *lookup, string *result) {
        for (int i = 0; i < k; ++i) {
            const auto& neighbor = node + to_string(i);
            if (!lookup->count(neighbor)) {
                lookup->emplace(neighbor);
                dfs(k, neighbor.substr(1), lookup, result);
                result->push_back('0' + i);
            }
        }
    }
};
