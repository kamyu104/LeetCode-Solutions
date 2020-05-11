// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        using RET = pair<int, int>;
        RET result{};
        vector<tuple<int, int, int, shared_ptr<RET>, RET *>> stk = {{1, -1, 0, nullptr, &result}};
        while (!stk.empty()) {
            const auto [step, par, node, new_ret, ret] = stk.back(); stk.pop_back();
            if (step == 1) {
                ret->second = int(hasApple[node]);
                for (const auto& nei : graph[node]) {
                    if (nei == par) {
                        continue;
                    }
                    const auto& new_ret = make_shared<RET>();
                    stk.emplace_back(2, -1, -1, new_ret, ret);
                    stk.emplace_back(1, node, nei, nullptr, new_ret.get());
                }
            } else {
                ret->first += new_ret->first + new_ret->second;
                ret->second |= bool(new_ret->first + new_ret->second);
            }
        }
        return 2 * result.first;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution_Recu {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        return 2 * dfs(graph, -1, 0, hasApple).first;
    }

private:
    pair<int, int> dfs(const unordered_map<int, vector<int>>& graph,
            int par, int node,
            const vector<bool>& hasApple) {
        int result = 0, extra = hasApple[node];
        for (const auto& nei : graph.at(node)) {
            if (nei == par) {
                continue;
            }
            const auto& [count, found] = dfs(graph, node, nei, hasApple);
            result += count + found;
            extra |= bool(count + found);
        }
        return {result, extra};
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        using RET = int;
        RET result{};
        vector<tuple<int, int, int, shared_ptr<RET>, shared_ptr<RET>, RET *>> stk = {{1, -1, 0, nullptr, nullptr, &result}};
        while (!stk.empty()) {
            const auto [step, par, node, new_ret, tmp, ret] = stk.back(); stk.pop_back();
            if (step == 1) {
                const auto& tmp = make_shared<RET>(hasApple[node]);
                stk.emplace_back(3, -1, -1, nullptr, tmp, ret);
                for (const auto& nei : graph[node]) {
                    if (nei == par) {
                        continue;
                    }
                    const auto& new_ret = make_shared<RET>();
                    stk.emplace_back(2, -1, -1, new_ret, tmp, ret);
                    stk.emplace_back(1, node, nei, nullptr, nullptr, new_ret.get());
                }
            } else if (step == 2) {
                *ret += *new_ret;
                *tmp |= bool(*new_ret);
            } else {
                *ret += *tmp;
            }
        }
        return 2 * max(result - 1, 0);
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2_Recu {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        return 2 * max(dfs(graph, -1, 0, hasApple) - 1, 0);
    }

private:
    int dfs(const unordered_map<int, vector<int>>& graph,
            int par, int node,
            const vector<bool>& hasApple) {
        int result = 0, extra = hasApple[node];
        for (const auto& nei : graph.at(node)) {
            if (nei == par) {
                continue;
            }
            const auto& count = dfs(graph, node, nei, hasApple);
            result += count;
            extra |= bool(count);
        }
        return result + extra;
    }
};
