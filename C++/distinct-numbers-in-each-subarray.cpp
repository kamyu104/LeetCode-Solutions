// Time:  O(n)
// Space: O(k)

class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> count;
        for (int i = 0; i < size(nums); ++i) {
            ++count[nums[i]];
            if (i >= k) {
                if (--count[nums[i - k]] == 0) {
                    count.erase(nums[i - k]);
                }
            }
            if (i + 1 >= k) {
                result.emplace_back(size(count));
            }
        }
        return result;
    }
};
