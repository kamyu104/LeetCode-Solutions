// Time:  ctor:        O(n^2)
//        adjacentSum: O(1)
//        diagonalSum: O(1)
// Space: O(n^2)

// hash table
class neighborSum {
public:
    neighborSum(vector<vector<int>>& grid)
        : grid_(grid)
        , lookup_(size(grid) * size(grid[0]))
    {
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                lookup_[grid[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        static const vector<pair<int, int>> ADJACENTS{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
        return sum(value, ADJACENTS);
    }
    
    int diagonalSum(int value) {
        static const vector<pair<int, int>> DIAGONALS{{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        return sum(value, DIAGONALS);
    }

private:
    int sum(int value, const auto& directions) {
        const auto& [i, j] = lookup_[value];
        int total = 0;
        for (const auto& [di, dj] : directions) {
            const int ni = i + di, nj = j + dj;
            if (!(0 <= ni && ni < size(grid_) && 0 <= nj && nj < size(grid_[0]))) {
                continue;
            }
            total += grid_[ni][nj];
        }
        return total;
    }

    vector<vector<int>> grid_;
    vector<pair<int, int>> lookup_;
};
