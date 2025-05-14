// Time:  O(m * n)
// Space: O(1)

// array
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int64_t total = accumulate(cbegin(grid), cend(grid), static_cast<int64_t>(0), [](const auto& accu, const auto& x) {
            return accumulate(cbegin(x), cend(x), accu);
        });
        if (total % 2) {
            return false;
        }
        total /= 2;
        const auto& check = [&](int begin1, int end1, int begin2, int end2, const auto& get) {
            int64_t curr = 0;
            const int d = begin1 < end1 ? 1 : -1;
            for (int i = begin1; i != end1; i += d) {
                for (int j = begin2; j != end2; ++j) {
                    curr += get(i, j);
                }
                if (curr == total) {
                    return true;
                } else if (curr > total) {
                    break;
                }
            }
            return false;
        };

        return check(0, size(grid), 0, size(grid[0]), [&](int i, int j) { return grid[i][j]; }) ||
               check(0, size(grid[0]), 0, size(grid), [&](int i, int j) { return grid[j][i]; });
    }
};
