// Time:  O(l + q)
// Space: O(l)

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

public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        static const vector<pair<int, int>> directions = 
            {{0, -1}, {0, 1}, {-1, 0}, {1, 0},
             {-1, -1}, {1, -1}, {1, -1}, {1, 1}};

        unordered_set<pair<int, int>, PairHash<int>> lookup;
        unordered_map<int, int> row;
        unordered_map<int, int> col;
        unordered_map<int, int> diag;
        unordered_map<int, int> anti;
        for (const auto& lamp : lamps) {
            int r, c;
            tie(r, c) = make_pair(lamp[0], lamp[1]);
            lookup.emplace(r, c);
            ++row[r];
            ++col[c];
            ++diag[r - c];
            ++anti[r + c];
        }
        
        vector<int> result;
        for (const auto& query : queries) {
            int r, c;
            tie(r, c) = make_pair(query[0], query[1]);
            if (row[r] || col[c] ||
                diag[r - c] || anti[r + c]) {
                result.emplace_back(1);
            } else {
                result.emplace_back(0);
            }
            for (const auto& d : directions) {
                int nr, nc;
                tie(nr, nc) = make_pair(r + d.first, c + d.second);
                if (!(0 <= nr && nr < N && 0 <= nc && nc < N &&
                      lookup.count(make_pair(nr, nc)))) {
                    continue;
                }
                lookup.erase(make_pair(nr, nc));
                --row[nr];
                --col[nc];
                --diag[nr - nc];
                --anti[nr + nc];
            }
        }
        return result;
    }
};
