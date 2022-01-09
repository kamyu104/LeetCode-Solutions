// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        const int w = count(cbegin(nums), cend(nums), 1);
        int result = w, cnt = w;
        for (int i = 0; i < size(nums) + (w - 1); ++i) {
            if (i >= w) {
                cnt += nums[(i - w) % size(nums)];
            }
            cnt -= nums[i % size(nums)];
            result = min(result, cnt);
        }
        return result;
    }
};
