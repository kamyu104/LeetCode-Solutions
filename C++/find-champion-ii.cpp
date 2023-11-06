// Time:  O(n)
// Space: O(n)

// graph, hash table
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> lookup(n);
        for (const auto& e : edges) {
            lookup[e[1]] = true;
        }
        int result = -1;
        for (int u = 0; u < n; ++u) {
            if (lookup[u]) {
                continue;
            }
            if (result != -1) {
                return -1;
            }
            result = u;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// graph, hash table
class Solution2 {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> lookup;
        for (const auto& e : edges) {
            lookup.emplace(e[1]);
        }
        if (size(lookup) != n - 1) {
            return -1;
        }
        for (int u = 0; u < n; ++u) {
            if (!lookup.count(u)) {
                return u;
            }
        }
        return -1;
    }
};
