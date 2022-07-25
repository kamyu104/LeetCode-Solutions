// Time:  O(n^2)
// Space: O(n^2)

// hash table
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<vector<int>, int, VectorHash<int>> cnt1;
        for (const auto& row : grid) {
            ++cnt1[row];
        }
        unordered_map<vector<int>, int, VectorHash<int>> cnt2;
        for (int j = 0; j < size(grid[0]); ++j) {
            vector<int> col(size(grid));
            for (int i = 0; i < size(grid); ++i) {
                col[i] = grid[i][j];
            }
            ++cnt2[col];
        }
        int result = 0;
        for (const auto& [k, _] : cnt1) {
            if (!cnt2.count(k)) {
                continue;
            }
            result += cnt1[k] * cnt2[k];
        }
        return result;
    }

private:
    template<typename T>
    struct VectorHash {
        size_t operator()(const std::vector<T>& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<T>{}(i)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };
};
