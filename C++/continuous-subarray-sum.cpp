// Time:  O(n)
// Space: O(k)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> lookup;
        lookup[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i];
            if (k != 0) {
                count %= k; 
            }
            if (lookup.count(count)) {
                if (i - lookup[count] > 1) {
                    return true;
                }
            } else {
                lookup[count] = i;
            }
        }
        return false;
    }
};
