// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) { 
        UnionFind union_find(s.length());
        for (const auto& pair : pairs) {
            union_find.union_set(pair[0], pair[1]);
        }
        unordered_map<int, vector<char>> components;
        for (int i = 0; i < s.length(); ++i) {
            components[union_find.find_set(i)].emplace_back(s[i]);
        }
        for (auto& [i, list] : components) {
            sort(list.begin(), list.end(), greater<char>());
        }
        for (int i = 0; i < s.length(); ++i) {
            const auto& j = union_find.find_set(i);
            s[i] = components[j].back();
            components[j].pop_back();
        }
        return s;
    }

private:
    class UnionFind {
    public:
        UnionFind(const int n) : set_(n) {
            iota(set_.begin(), set_.end(), 0);
        }

        int find_set(const int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
        }

        bool union_set(const int x, const int y) {
            int x_root = find_set(x), y_root = find_set(y);
            if (x_root == y_root) {
                return false;
            }
            set_[min(x_root, y_root)] = max(x_root, y_root);
            return true;
        }

    private:
        vector<int> set_;
    };
};

// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) { 
        unordered_map<int, vector<int>> adj;
        for (const auto& pair : pairs) {
            adj[pair[0]].emplace_back(pair[1]);
            adj[pair[1]].emplace_back(pair[0]);
        }
        unordered_set<int> lookup;
        string result = s;
        for (int i = 0; i < s.length(); ++i) {
            if (lookup.count(i)) {
                continue;
            }
            vector<int> component;
            dfs(i, adj, &lookup, &component);
            sort(component.begin(), component.end());
            vector<char> chars;
            for (const auto& k : component) {
                chars.emplace_back(result[k]);
            }
            sort(chars.begin(), chars.end());
            for (int j = 0; j < component.size(); ++j) {
                result[component[j]] = chars[j];
            }
        }
        return result;
    }

private:
    void dfs(int i, const unordered_map<int, vector<int>>& adj,
             unordered_set<int> *lookup, vector<int> *component) {
        lookup->emplace(i);
        component->emplace_back(i);
        if (!adj.count(i)) {
            return;
        }
        for (const auto& j : adj.at(i)) {
            if (lookup->count(j)) {
                continue;
            }
            dfs(j, adj, lookup, component);
        }
    }
};
