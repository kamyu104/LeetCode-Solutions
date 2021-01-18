// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < size(nums); ++i) {
            for (int j = i + 1; j < size(nums); ++j) {
                result += count[nums[i] * nums[j]]++;
            }
        }
        return 8 * result;
    }
};
