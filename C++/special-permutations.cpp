// Time:  O(n^2 * 2^n)
// Space: O(n * 2^n)

// backtracking, memoization
class Solution {
public:
    int specialPerm(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        vector<vector<int>> lookup(size(nums) + 1, vector<int>(1 << size(nums), -1));
        function<int (int, int)> backtracking = [&](int i, int mask) {
            if (mask == (1 << size(nums)) - 1) {
                return 1;
            }
            if (lookup[i + 1][mask] == -1) {
                int total = 0;
                for (int j = 0; j < size(nums); ++j) {
                    if (mask & (1 << j)) {
                        continue;
                    }
                    if (!(i == -1 || nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)) {
                        continue;
                    }
                    total = (total + backtracking(j, mask | (1 << j))) % MOD;
                }
                lookup[i + 1][mask] = total;
            }
            return lookup[i + 1][mask];
        };

        return backtracking(-1, 0);
    }
};
