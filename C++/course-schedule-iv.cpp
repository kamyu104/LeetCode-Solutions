// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        const auto& reachable = floydWarshall(n, prerequisites);
        vector<bool> result;
        for (const auto& q : queries) {
            result.emplace_back(reachable.count(q[0] * n + q[1]));
        }
        return result;
    }

private:
    unordered_set<int> floydWarshall(int n, const vector<vector<int>>& graph) {
        unordered_set<int> reachable;
        for (const auto& connected : graph) {
            reachable.emplace(connected[0] * n + connected[1]);
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (!reachable.count(i * n + j) &&
                        (reachable.count(i * n + k) && reachable.count(k * n + j))) {
                        reachable.emplace(i * n + j);
                    }
                }
            }
        }
        return reachable;
    }
};

// Time:  O(n * q)
// Space: O(p + n)
class Solution_TLE {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> graph;
        for (const auto& connected : prerequisites) {
            graph[connected[0]].emplace_back(connected[1]);
        }
        vector<bool> result;
        for (const auto& q : queries) {
            vector<int> stk = {q[0]};
            unordered_set<int> lookup = {q[0]};
            while (!stk.empty()) {
                const auto node = stk.back(); stk.pop_back();
                for (const auto& nei : graph[node]) {
                    if (lookup.count(nei)) {
                        continue;
                    }
                    stk.emplace_back(nei);
                    lookup.emplace(nei);
                }
            }
            result.emplace_back(lookup.count(q[1]));
        }
        return result;
    }
};
