// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> graph(26);
        for (const auto& eqn : equations) {
            int x = eqn[0] - 'a';
            int y = eqn[3] - 'a';
            if (eqn[1] == '!') {
                if (x == y) {
                    return false;
                }
            } else {
                graph[x].emplace_back(y);
                graph[y].emplace_back(x);
            }
        }

        vector<int> color(26);
        for (int i = 0, c = 0; i < color.size(); ++i) {
            if (color[i]) {
                continue;
            }
            ++c;
            vector<int> stack = {c};
            while (!stack.empty()) {
                int node = stack.back(); stack.pop_back();
                for (const auto& nei : graph[node]) {
                    if (!color[nei]) {
                        color[nei] = c;
                        stack.emplace_back(nei);
                    }
                }
            }
        }

        for (const auto& eqn : equations) {
            if (eqn[1] != '!') {
                continue;
            }
            int x = eqn[0] - 'a';
            int y = eqn[3] - 'a';
            if (color[x] && color[x] == color[y]) {
                return false;
            }
        }
        return true; 
    }
};
