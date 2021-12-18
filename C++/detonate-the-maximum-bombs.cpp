// Time:  O(|V|^2 + |V| * |E|)
// Space: O(|V| + |E|)

// bfs solution
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> adj(size(bombs));
        for (int i = 0; i < size(bombs); ++i) {
            for (int j = 0; j < size(bombs); ++j) {
                if (j == i) {
                    continue;
                }
                const int64_t dx = bombs[i][0] - bombs[j][0];
                const int64_t dy = bombs[i][1] - bombs[j][1];
                const int64_t r = bombs[i][2];
                if (dx * dx + dy * dy <= r * r) {
                    adj[i].emplace_back(j);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < size(bombs); ++i) {
            vector<int> q = {i};
            unordered_set<int> lookup = {i};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (lookup.count(v)) {
                            continue;
                        }
                        lookup.emplace(v);
                        new_q.emplace_back(v);
                    }
                }
                q = new_q;
            }
            result = max(result, static_cast<int>(size(lookup)));
            if (result == size(bombs)) {
                break;
            }
        }
        return result;
    }
};

// Time:  O(|V|^2 + |V| * |E|)
// Space: O(|V| + |E|)
// dfs solution
class Solution2 {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> adj(size(bombs));
        for (int i = 0; i < size(bombs); ++i) {
            for (int j = 0; j < size(bombs); ++j) {
                if (j == i) {
                    continue;
                }
                const int64_t dx = bombs[i][0] - bombs[j][0];
                const int64_t dy = bombs[i][1] - bombs[j][1];
                const int64_t r = bombs[i][2];
                if (dx * dx + dy * dy <= r * r) {
                    adj[i].emplace_back(j);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < size(bombs); ++i) {
            vector<int> stk = {i};
            unordered_set<int> lookup = {i};
            while (!empty(stk)) {
                const int u = stk.back(); stk.pop_back();
                for (const auto& v : adj[u]) {
                    if (lookup.count(v)) {
                        continue;
                    }
                    lookup.emplace(v);
                    stk.emplace_back(v);
                }
            }
            result = max(result, static_cast<int>(size(lookup)));
            if (result == size(bombs)) {
                break;
            }
        }
        return result;
    }
};
