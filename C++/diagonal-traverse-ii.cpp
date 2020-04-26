// Time:  O(m * n)
// Space: O(m)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        const auto& n = accumulate(nums.cbegin(), nums.cend(), uint64_t(0ull),
                                   [](const auto& x, const auto& y) {
                                       return max(x, y.size());
                                   });
        vector<int> result;
        deque<pair<int, int>> dq;
        for (int r = 0; r < nums.size() + n - 1; ++r) {
            deque<pair<int, int>> new_dq;
            if (r < nums.size()) {
                dq.emplace_front(r, 0);
            }
            for (const auto& [r, c] : dq) {
                result.emplace_back(nums[r][c]);
                if (c + 1 < nums[r].size()) {
                    new_dq.emplace_back(r, c + 1);
                }
            }
            dq = move(new_dq);
        }
        return result;
    }
};

// Time:  O(m * n)
// Space: O(m * n)
class Solution2 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> ans;
        for (int r = 0; r < nums.size(); ++r) {
            for (int c = 0; c < nums[r].size(); ++c) {
                if (ans.size() <= r + c) {
                    ans.emplace_back();
                }
                ans[r + c].emplace_back(nums[r][c]);
            }
        }
        vector<int> result;
        for (const auto& row: ans) {
            for (int i = row.size() - 1; i >= 0; --i) {
                result.emplace_back(row[i]);
            }
        }
        return result;
    }
};
