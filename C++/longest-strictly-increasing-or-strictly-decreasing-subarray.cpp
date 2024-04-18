// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result = 1, cnt1 = 1, cnt2 = 1;
        for (int i = 1; i < size(nums); ++i) {
            if (nums[i - 1] < nums[i]) {
                ++cnt1;
                cnt2 = 1;
            } else if (nums[i - 1] > nums[i]) {
                ++cnt2;
                cnt1 = 1;
            } else {
                cnt1 = cnt2 = 1;
            }
            result = max({result, cnt1, cnt2});
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
