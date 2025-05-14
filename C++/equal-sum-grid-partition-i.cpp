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
        const auto& check1 = [&]() {
            int64_t curr = 0;
            for (int i = 0; i < size(grid); ++i) {
                for (int j = 0; j < size(grid[0]); ++j) {
                    curr += grid[i][j];
                }
                if (curr == total) {
                    return true;
                } else if (curr > total) {
                    break;
                }
            }
            return false;
        };

        const auto& check2 = [&]() {
            int64_t curr = 0;
            for (int j = 0; j < size(grid[0]); ++j) {
                for (int i = 0; i < size(grid); ++i) {
                    curr += grid[i][j];
                }
                if (curr == total) {
                    return true;
                } else if (curr > total) {
                    break;
                }
            }
            return false;
        };

        return check1() || check2();
    }
};
