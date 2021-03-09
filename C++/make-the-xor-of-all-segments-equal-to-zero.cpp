// Time:  O(n + k * m), m is the max number of nums
// Space: O(min(k * m, n))

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<unordered_map<int, int>> cnts(k);
        for (int i = 0; i < size(nums); ++i) {
            ++cnts[i % k][nums[i]];
        }
        return min(one_are_not_from_nums(nums, cnts), all_are_from_nums(nums, cnts));
    }

private:
    int all_are_from_nums(const vector<int>& nums, const vector<unordered_map<int, int>>& cnts) {
        unordered_map<int, int> dp{{0, 0}};
        for (const auto& cnt : cnts) {
            unordered_map<int, int> new_dp;
            for (const auto& [x, dp_x] : dp) {
                for (const auto& [y, cnt_y] : cnt) {
                    new_dp[x ^ y] = max(new_dp[x ^ y], dp_x + cnt_y);
                }
            }
            dp = move(new_dp);
        }
        return size(nums) - dp[0];
    }

    int one_are_not_from_nums(const vector<int>& nums, const vector<unordered_map<int, int>>& cnts) {
        static const auto& cmp =
            [](auto x, auto y) {
                return x.second < y.second;
            };
        vector<int> mxs;
        int tot_mx = 0, mn_mx = numeric_limits<int>::max();
        for (const auto& cnt : cnts) {
            int mx = max_element(cbegin(cnt), cend(cnt), cmp)->second;
            tot_mx += mx;
            mn_mx = min(mn_mx, mx);
        }
        return size(nums) - (tot_mx - mn_mx);
    }
};
