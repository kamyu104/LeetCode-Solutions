// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> lookup = {{0, -1}};
        int result = 0, accu = 0, right = -1;
        for (int i = 0; i < nums.size(); ++i) {
            accu += nums[i];
            if (lookup.count(accu - target) && lookup[accu - target] >= right) {
                right = i;
                ++result;  // greedy
            }
            lookup[accu] = i;
        }
        return result; 
    }
};
