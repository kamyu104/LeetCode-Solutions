// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int result = 0, u = 0;  // we can start from any node as u
        vector<int> dist(size(points), numeric_limits<int>::max());
        unordered_set<int> lookup;
        for (int i = 0; i < size(points) - 1; ++i) {
            int x0 = points[u][0], y0 = points[u][1];
            lookup.emplace(u);
            for (int v = 0; v < size(points); ++v) {
                if (lookup.count(v)) {
                    continue;
                }
                dist[v] = min(dist[v], abs(points[v][0] - x0) + abs(points[v][1] - y0));
            }
            int val = numeric_limits<int>::max();
            for (int v = 0; v < size(dist); ++v) {
                if (dist[v] < val) {
                    val = dist[v];
                    u = v;
                }
            }
            dist[u] = numeric_limits<int>::max();  // used
            result += val;
        }
        return result;
    }
};

// Time:  O(eloge) = O(n^2 * logn)
// Space: O(e) = O(n^2)
// kruskals' algorithm
class Solution2 {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int, int, int>> edges;
        for (int u = 0; u < size(points); ++u) {
            for (int v = u + 1; v < size(points); ++v) {
                edges.emplace_back(u, v, abs(points[v][0] - points[u][0]) + abs(points[v][1] - points[u][1]));
            }
        }
        sort(begin(edges), end(edges),
             [](const auto& a, const auto& b) {
                return get<2>(a) < get<2>(b); 
             });
        UnionFind union_find(size(points));
        int result = 0;
        for (const auto& [u, v, val] : edges) {
            if (union_find.union_set(u, v)) {
                result += val;
            }
        }
        return result;
    }
    
private:
    class UnionFind {
    public:
        UnionFind(const int n) : set_(n), rank_(n), count_(n) {
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
            if (rank_[x_root] < rank_[y_root]) {  // Union by rank.
                set_[x_root] = y_root;
            } else if (rank_[x_root] > rank_[y_root]) {
                set_[y_root] = x_root;
            } else {
                set_[y_root] = x_root;
                ++rank_[x_root];
            }
            --count_;
            return true;
        }

        int size() const {
            return count_;
        }

    private:
        vector<int> set_;
        vector<int> rank_;
        int count_;
    };
};
