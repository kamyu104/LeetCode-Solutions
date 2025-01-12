// Time:  O(n)
// Space: O(n)

// freq table, prefix sum, combinatorics
class Solution {
public:
    int subsequencesWithMiddleMode(vector<int>& nums) {
        typedef __int128 int128_t;

        const auto& nC2 = [](int128_t x) {
            return x * (x - 1) / 2;
        };

        static const int MOD = 1e9 + 7;
        int128_t result = 0;
        unordered_map<int, int128_t> left, right;
        for (const auto& x : nums) {
            ++right[x];
        }

        int128_t left_x_sq = 0; // sum(left[x]^2 for x != v)
        int128_t right_x_sq = 0; // sum(right[x]^2f or x != v)
        int128_t left_x_right_x = 0;  // sum(left[x]*right[x] for x != v)
        int128_t left_x_sq_right_x = 0;  // sum(left[x]^2*right[x] for x != v)
        int128_t left_x_right_x_sq = 0;  //sum(left[x]*right[x]^2 for x != v)
        for (const auto& [_, v] : right) {
            right_x_sq += v * v;
        }
        for (int i = 0; i < size(nums); ++i) {
            const int v = nums[i];
            left_x_sq -= left[v] * left[v];
            right_x_sq -= right[v]* right[v];
            left_x_right_x -= left[v] * right[v];
            left_x_sq_right_x -= left[v] * left[v] * right[v];
            left_x_right_x_sq -= left[v] * right[v] * right[v];
            --right[v];

            const int l = i;
            const int r = size(nums) - (i + 1);
            // all possibles
            result += nC2(l) * nC2(r);
            // only mid is a
            result -= nC2(l - left[v]) * nC2(r - right[v]);
            // bb/a/ac
            // sum((left[x]*(left[x]-1)//2)*right[v]*((r-right[v])-right[x]) for x != v)
            result -= ((left_x_sq - (l - left[v])) * (r - right[v]) - (left_x_sq_right_x - left_x_right_x)) * right[v] / 2;
            // ac/a/bb
            // sum(left[v]*((l-left[v])-left[x])*(right[x]*(right[x]-1)//2) for x != v)
            result -= ((right_x_sq - (r - right[v])) * (l - left[v]) - (left_x_right_x_sq - left_x_right_x) ) *left[v] / 2;
            // ab/a/bc
            // sum(left[v]*left[x]*right[x]*((r-right[v])-right[x]) for x != v)
            result -= left[v] * left_x_right_x * (r - right[v]) - left[v] * left_x_right_x_sq;
            // bc/a/ab
            // sum(left[x]*((l-left[v])-left[x])*right[v]*right[x] for x != v)
            result -= right[v] * left_x_right_x * (l - left[v]) - right[v] * left_x_sq_right_x;
            // bb/a/ab
            // sum((left[x]*(left[x]-1)//2)*right[v]*right[x] for x != v)
            result -= right[v] * (left_x_sq_right_x - left_x_right_x) / 2;
            // ab/a/bb
            // sum((right[x]*(right[x]-1)//2)*left[v]*left[x] for x != v)
            result -= left[v] * (left_x_right_x_sq - left_x_right_x) / 2;

            ++left[v];
            left_x_sq += left[v] * left[v];
            right_x_sq += right[v] * right[v];
            left_x_right_x += left[v] * right[v];
            left_x_sq_right_x += left[v] * left[v] * right[v];
            left_x_right_x_sq += left[v] * right[v] * right[v];
        }

        return result % MOD;
    }
};
