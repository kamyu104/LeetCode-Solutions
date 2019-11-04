// Time:  O(n^2), n is the number of blocked
// Space: O(n)

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
    
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<pair<int, int>, PairHash<int>> blocks;
        for (const auto& block : blocked) {
            blocks.emplace(block[0], block[1]);
        }
        return bfs(blocks, make_pair(source[0], source[1]), make_pair(target[0], target[1])) &&
               bfs(blocks, make_pair(target[0], target[1]), make_pair(source[0], source[1]));
    }
    
private:
    bool bfs(const unordered_set<pair<int, int>, PairHash<int>>& blocks,
             const pair<int, int>& source, const pair<int, int>& target) {
        static const int R = 1e6;
        static const int C = 1e6;
        static const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                       {-1, 0}, {1, 0}};

        const auto& max_area_surrounded_by_blocks = blocks.size() * (blocks.size() - 1) / 2;
        unordered_set<pair<int, int>, PairHash<int>> lookup{source};
        if (lookup.size() > max_area_surrounded_by_blocks) {
            return true;
        }
        queue<pair<int, int>> q({source});
        while (!q.empty()) {
            auto source = q.front();  q.pop();
            if (source == target) {
                return true;
            }
            for (const auto& dir : directions) {
                const auto nr = source.first + dir.first, nc = source.second + dir.second;
                
                if (!((0 <= nr && nr < R) &&
                      (0 <= nc && nc < C) &&
                      !lookup.count(make_pair(nr, nc)) &&
                      !blocks.count(make_pair(nr, nc)))) {
                    continue;
                }
                lookup.emplace(nr, nc);
                if (lookup.size() > max_area_surrounded_by_blocks) {
                    return true;
                }
                q.emplace(nr, nc);
            }
        }
        return false;
    }
};
