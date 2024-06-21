// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        const auto& cmp = [](int x, int y) {
            return x < y ? -1 : (x > y ? 1 : 0);
        };

        int result = 1;
        for (int i = 1, cnt = 1, curr = 0, prev = 0; i < size(nums); ++i, prev = curr) {
            curr = cmp(nums[i - 1], nums[i]);
            if (curr == 0) {
                cnt = 1;
                continue;
            }
            cnt = (curr == prev ? cnt : 1) + 1;
            result = max(result, cnt);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// array
class Solution2 {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result = 1;
        for (int i = 1, cnt1 = 1, cnt2 = 1; i < size(nums); ++i) {
            cnt1 = nums[i - 1] < nums[i] ?  cnt1 + 1 : 1;
            cnt2 = nums[i - 1] > nums[i] ?  cnt2 + 1 : 1;
            result = max({result, cnt1, cnt2});
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// array
class Solution3 {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        const auto& f = [&](const auto& compare) {
            int result = 0;
            for (int i = 0, l = 0; i < size(nums); ++i) {
                ++l;
                if (i + 1 == size(nums) || !compare(nums[i], nums[i + 1])) {
                    result = max(result, l);
                    l = 0;
                }
            }
            return result;
        };

        return max(f(less<int>()), f(greater<int>()));
    }
};
