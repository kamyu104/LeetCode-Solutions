// Time:  O(m * n)
// Space: O(m * n)

// array, hash table
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        const int64_t total = accumulate(cbegin(grid), cend(grid), static_cast<int64_t>(0), [](const auto& accu, const auto& x) {
            return accumulate(cbegin(x), cend(x), accu);
        });
        const auto& check = [&](int begin1, int end1, int begin2, int end2, const auto& get) {
            int64_t curr = 0;
            const int d = begin1 < end1 ? 1 : -1;
            unordered_set<int64_t> lookup;
            for (int i = begin1; i != end1; i += d) {
                for (int j = begin2; j != end2; ++j) {
                    curr += get(i, j);
                    lookup.emplace(get(i, j));
                }
                const int64_t diff = curr - (total - curr);
                if (diff == 0) {
                    return true;
                }
                if (i != begin1 && end2 - begin2 != 1) {
                    if (lookup.count(diff)) {
                        return true;
                    }
                } else if (i == begin1) {
                    if (get(begin1, begin2) == diff || get(begin1, end2 - 1) == diff) {
                        return true;
                    }
                } else {
                    if (get(begin1, 0) == diff || get(i, 0) == diff) {
                        return true;
                    }
                }
            }
            return false;
        };

        return check(0, size(grid), 0, size(grid[0]), [&](int i, int j) { return grid[i][j]; }) ||
               check(size(grid) - 1, -1, 0, size(grid[0]), [&](int i, int j) { return grid[i][j]; }) ||
               check(0, size(grid[0]), 0, size(grid), [&](int i, int j) { return grid[j][i]; }) ||
               check(size(grid[0]) - 1, -1, 0, size(grid), [&](int i, int j) { return grid[j][i]; });
    }
};
