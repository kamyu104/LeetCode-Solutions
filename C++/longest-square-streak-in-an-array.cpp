// Time:  O(nlogn)
// Space: O(n)

// hash table
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int64_t> sorted_nums(cbegin(nums), cend(nums));
        unordered_set<int64_t> squares;
        for (const auto& x : sorted_nums) {
            if (x % 4 < 2) {  // squared_num % 4 in [0, 1]
                squares.emplace(x);
            }
        }
        int result = 0;
        for (const auto& x : sorted_nums) {
            int cnt = 1;
            for (int64_t square = x * x; squares.count(square); squares.erase(square), square *= square) {
                ++cnt;
            }
            result = max(result, cnt);
        }
        return result != 1 ? result : -1;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// dp
class Solution2 {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(begin(nums), end(nums));
        unordered_map<int, int> dp;
        int result = 0;
        for (const auto& x : nums) {
            const int sqrt_x = static_cast<int>(sqrt(x));
            if (sqrt_x * sqrt_x == x) {
                dp[x] = dp[sqrt_x] + 1;
            } else {
                dp[x] = 1;
            }
            result = max(result, dp[x]);
        }
        return result != 1 ? result : -1;
    }
};
