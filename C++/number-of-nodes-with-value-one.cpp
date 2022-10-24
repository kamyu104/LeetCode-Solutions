// Time:  O(q + n)
// Space: O(n)

// bfs
class Solution {
public:
    int numberOfNodes(int n, vector<int>& queries) {
        vector<int> cnt(n);
        const auto& bfs = [&]() {
            int result = 0;
            vector<pair<int, int>> q = {{1, 0}};
            while (!empty(q)) {
                vector<pair<int, int>> new_q;
                for (auto [u, curr] : q) {
                    curr ^= cnt[u - 1] % 2;
                    result += curr;
                    for (int v = 2 * u; v <= min(2 * u + 1, n); ++v) {
                        new_q.emplace_back(v, curr);
                    }
                }
                q = move(new_q);                
            }
            return result;
        };
        
        for (const auto& q : queries) {
            ++cnt[q - 1];
        }
        return bfs();
    }
};

// Time:  O(q + n)
// Space: O(q + h)
// iterative dfs
class Solution2 {
public:
    int numberOfNodes(int n, vector<int>& queries) {
        vector<int> cnt(n);
        const auto& iter_dfs = [&]() {
            int result = 0;
            vector<pair<int, int>> stk = {{1, 0}};
            while (!empty(stk)) {
                auto [u, curr] = stk.back(); stk.pop_back();
                curr ^= cnt[u - 1] % 2;
                result += curr;
                for (int v = 2 * u; v <= min(2 * u + 1, n); ++v) {
                    stk.emplace_back(v, curr);
                }
            }
            return result;
        };

        for (const auto& q : queries) {
            ++cnt[q - 1];
        }
        return iter_dfs();
    }
};

// Time:  O(q + n)
// Space: O(q + h)
// dfs
class Solution3 {
public:
    int numberOfNodes(int n, vector<int>& queries) {
        vector<int> cnt(n);
        const function<int(int, int)> dfs = [&](int u, int curr) {
            curr ^= cnt[u - 1] % 2;
            int result = curr;
            for (int v = 2 * u; v <= min(2 * u + 1, n); ++v) {
                result += dfs(v, curr);
            }
            return result;
        };
        
        for (const auto& q : queries) {
            ++cnt[q - 1];
        }
        return dfs(1, 0);
    }
};
