// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0, count = 0;
        unordered_map<int, int> lookup;
        lookup[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i] == 1 ? 1 : -1;
            if (lookup.count(count)) {
                result = max(result, i - lookup[count]);
            } else {
                lookup[count] = i;
            }
        }
        return result;
    }
};
