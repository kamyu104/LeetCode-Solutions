// Time:  O(n)
// Space: O(1)

// array
class Solution {
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
