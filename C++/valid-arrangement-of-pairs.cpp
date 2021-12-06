// Time:  O(|V| + |E|)
// Space: O(|V| + |E|)

// Hierholzer Algorithm
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> degree;
        for (const auto& pair : pairs) {
            adj[pair[0]].emplace_back(pair[1]);
            ++degree[pair[0]];
            --degree[pair[1]];
        }
        int x = -1;
        for (auto& [k, v] : degree) {
            if (v == 1) {
                x = k;
                break;
            }
            if (x == -1) {
                x = k;
            }
        }
        vector<int> route;
        vector<int> stk = {x};
        while (!empty(stk)) {
            while (!empty(adj[stk.back()])) { 
                auto x = adj[stk.back()].back();
                adj[stk.back()].pop_back();
                stk.emplace_back(x);
                
            }
            route.emplace_back(stk.back());
            stk.pop_back();
        }
        reverse(begin(route), end(route));
        vector<vector<int>> result;
        for (int i = 0; i + 1 < size(route); ++i) {
            result.push_back({route[i], route[i + 1]});
        }
        return result;
    }
};
