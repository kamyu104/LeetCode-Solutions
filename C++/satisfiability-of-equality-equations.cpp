// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind union_find(26);
        for (const auto& eqn : equations) {
            int x = eqn[0] - 'a';
            int y = eqn[3] - 'a';
            if (eqn[1] == '=') {
                union_find.union_set(x, y);
            }
        }
        for (const auto& eqn : equations) {
            int x = eqn[0] - 'a';
            int y = eqn[3] - 'a';
            if (eqn[1] == '!') {
                if (union_find.find_set(x) == union_find.find_set(y)) {
                    return false;
                }
            }
        }
        return true; 
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

// Time:  O(n)
// Space: O(1)
class Solution2 {
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
