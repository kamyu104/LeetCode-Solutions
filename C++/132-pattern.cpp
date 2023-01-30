// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int ak = numeric_limits<int>::min();
        vector<int> stk;
        for (int i = size(nums) - 1; i >= 0; --i) {
            if (nums[i] < ak) {
                return true;
            }
            while (!empty(stk) && stk.back() < nums[i]) {
                ak = stk.back(), stk.pop_back(); 
            }
            stk.emplace_back(nums[i]);
        }
        return false;
    }
};

// Time:  O(n^2)
// Space: O(1)
class Solution_TLE {
public:
    bool find132pattern(vector<int>& nums) {
        for (int k = 0; k < size(nums); ++k) {
            bool valid = false;
            for (int j = 0; j < k; ++j) {
                if (nums[j] < nums[k]) {
                    valid = true;
                } else if (nums[j] > nums[k]) {
                    if (valid) {
                        return true;
                    }
                }
           }
        }
        return false;
    }
};
