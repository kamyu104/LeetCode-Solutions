// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
    
    int shortestBridge(vector<vector<int>>& A) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        unordered_set<pair<int, int>, PairHash<int>> lookup;
        unordered_set<pair<int, int>, PairHash<int>> target;
        auto islands = get_islands(A);
        lookup = move(islands[0]);
        target = move(islands[1]);
        queue<pair<pair<int, int>, int>> q;
        for (const auto& node : lookup) {
            q.emplace(node, 0);
        }
        while (!q.empty()) {
            pair<int, int> node;
            int dis;
            tie(node, dis) = q.front(); q.pop();
            if (target.count(node)) {
                return dis - 1;
            }
            for (const auto& d : directions) {
                pair<int, int> nei = make_pair(node.first + d.first, node.second + d.second);
                if (0 > nei.first || nei.first >= A.size() ||
                    0 > nei.second || nei.second >= A[0].size() ||
                    lookup.count(nei)) {
                    continue;
                }
                q.emplace(nei, dis + 1);
                lookup.emplace(nei);
            }
        }
    }

private:
    vector<unordered_set<pair<int, int>, PairHash<int>>> get_islands(const vector<vector<int>>& A) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        vector<unordered_set<pair<int, int>, PairHash<int>>> islands;
        unordered_set<pair<int, int>, PairHash<int>> done;
        for (int r = 0; r < A.size(); ++r) {
            for (int c = 0; c < A[0].size(); ++c) {
                if (A[r][c] == 0 || done.count(make_pair(r, c))) {
                    continue;
                }
                vector<pair<int, int>> s{{r, c}};
                unordered_set<pair<int, int>, PairHash<int>> lookup(s.cbegin(), s.cend());
                while (!s.empty()) {
                    auto node = s.back(); s.pop_back();
                    for (const auto& d : directions) {
                        pair<int, int> nei = make_pair(node.first + d.first, node.second + d.second);
                        if (0 > nei.first || nei.first >= A.size() ||
                            0 > nei.second || nei.second >= A[0].size() ||
                            lookup.count(nei) || A[nei.first][nei.second] == 0) {
                            continue;
                        }
                        s.emplace_back(nei);
                        lookup.emplace(nei);
                    }
                }
                for (const auto& node : lookup) {
                    done.emplace(node);
                }
                islands.emplace_back(move(lookup));
                if (islands.size() == 2) {
                    break;
                }
            }
        }
        return islands;
    }
};
