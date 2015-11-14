class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> numbers;
        int number = 0;
        const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                {-1, 0}, {1, 0}};
        unordered_map<int, int> set;
        for (const auto& position : positions) {
            const auto& node = make_pair(position.first, position.second);
            set[node_id(node, n)] = node_id(node, n);

            // For each direction, count distinct islands.
            unordered_set<int> neighbors;
            for (const auto& d : directions) {
                const auto& neighbor = make_pair(position.first + d.first,
                                                 position.second + d.second);
                if (neighbor.first >= 0 && neighbor.first < m &&
                    neighbor.second >= 0 && neighbor.second < n &&
                    set.find(node_id(neighbor, n)) != set.end()) {
                    neighbors.emplace(find_set(node_id(neighbor, n), &set));
                }
            }

            // For each direction, find and union.
            for (const auto& d : directions) {
                const auto& neighbor = make_pair(position.first + d.first,
                                                 position.second + d.second);
                if (neighbor.first >= 0 && neighbor.first < m &&
                    neighbor.second >= 0 && neighbor.second < n &&
                    set.find(node_id(neighbor, n)) != set.end()) {
                    union_set(&set, node_id(node, n), node_id(neighbor, n));
                }
            }

            number += 1 - neighbors.size();
            numbers.emplace_back(number);
        }
        return numbers;
    }

    int node_id(const pair<int, int>& node, const int n) {
        return node.first * n + node.second;
    }

    int find_set(int x, unordered_map<int, int> *set) {
       if ((*set)[x] != x) {
           (*set)[x] = find_set((*set)[x], set);  // path compression.
       }
       return (*set)[x];
    }

    void union_set(unordered_map<int, int> *set, const int x, const int y) {
        int x_root = find_set(x, set), y_root = find_set(y, set);
        (*set)[min(x_root, y_root)] = max(x_root, y_root);
    }
};
