// Time:  O(nlogr)
// Space: O(1)

// array
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        const auto& total = [](int x) {
            int result = 0;
            for (; x; x /= 10) {
                result += x % 10;
            }
            return result;
        };

        for (int i = 0; i < size(nums); ++i) {
            if (total(nums[i]) == i) {
                return i;
            }
        }
        return -1;
    }
};
