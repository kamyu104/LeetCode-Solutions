// Time:  O(n)
// Space: O(n)

// mono stack
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<int> result(size(nums), -1), stk1, stk2;
        for (int i = 0; i < size(nums); ++i) {
            while (!empty(stk2) && nums[stk2.back()] < nums[i]) {
                result[stk2.back()] = nums[i]; stk2.pop_back();
            }
            vector<int> tmp;
            while (!empty(stk1) && nums[stk1.back()] < nums[i]) {
                tmp.emplace_back(stk1.back()); stk1.pop_back();
            }
            stk1.emplace_back(i);
            for (int j = size(tmp) - 1; j >= 0; --j) {
                stk2.emplace_back(tmp[j]);
            }
        }
        return result;
    }
};
