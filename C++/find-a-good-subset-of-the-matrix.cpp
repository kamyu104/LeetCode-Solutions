// Time:  O(m * 2^n)
// Space: O(2^n)

// bitmasks, constructive algorithms, greedy, submask enumeration
class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(grid); ++i) {
            int mask = 0;
            for (int j = 0; j < size(grid[0]); ++j) {
                mask |= grid[i][j] << j;
            }
            if (!mask) {
                return {i};
            }
            for (int mask2 = ((1 << size(grid[0])) - 1) ^ mask, submask = mask2; submask > 0; submask = (submask - 1) & mask2) {
                if (lookup.count(submask)) {
                    return {lookup[submask], i};
                }
            }
            lookup[mask] = i;
        }
        return {};
    }
};

// Time:  O(m * 2^n)
// Space: O(2^n)
// bitmasks, constructive algorithms, greedy
class Solution2 {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(grid); ++i) {
            int mask = 0;
            for (int j = 0; j < size(grid[0]); ++j) {
                mask |= grid[i][j] << j;
            }
            if (!mask) {
                return {i};
            }
            for (int mask2 = 1; mask2 < 1 << size(grid[0]); ++mask2) {
                if (mask & mask2) {
                    continue;
                }
                if (lookup.count(mask2)) {
                    return {lookup[mask2], i};
                }
            }
            lookup[mask] = i;
        }
        return {};
    }
};
