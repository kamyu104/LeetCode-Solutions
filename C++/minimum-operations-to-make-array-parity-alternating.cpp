// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        static const int POS_INF = numeric_limits<int>::max();
        static const int NEG_INF = numeric_limits<int>::min();

        const auto& count = [&](int target) {
            int cnt = 0;
            int mn = POS_INF, mx = NEG_INF;
            for (int i = 0; i < size(nums); ++i) {
                if ((nums[i] & 1) == ((i & 1) ^ target)) {
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                } else {
                    ++cnt;
                    mn = min(mn,  nums[i] + 1);
                    mx = max(mx,  nums[i] - 1);
                }
            }
            return vector<int>{cnt, size(nums) == 1 ? 0 : (ranges::max(nums) == ranges::min(nums) ? 1 : mx - mn)};
        };

        return min(count(0), count(1));
    }
};

// Time:  O(n)
// Space: O(1)
// greedy
class Solution2 {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        static const int POS_INF = numeric_limits<int>::max();
        static const int NEG_INF = numeric_limits<int>::min();

        const auto& count = [&](int target) {
            int cnt = 0;
            int mn = ranges::min(nums), mx = ranges::max(nums);
            int mn2 = POS_INF, mx2 = NEG_INF;
            for (int i = 0; i < size(nums); ++i) {
                if ((nums[i] & 1) == ((i & 1) ^ target)) {
                    mn2 = min(mn2, nums[i]);
                    mx2 = max(mx2, nums[i]);
                } else {
                    ++cnt;
                    if (nums[i] == mn) {
                        mn2 = min(mn2, nums[i] + 1);
                        mx2 = max(mx2, nums[i] + 1);
                    } else if (nums[i] == mx) {
                        mn2 = min(mn2, nums[i] - 1);
                        mx2 = max(mx2, nums[i] - 1);
                    }
                }
            }
            return vector<int>{cnt, mx2 - mn2};
        };

        return min(count(0), count(1));
    }
};
