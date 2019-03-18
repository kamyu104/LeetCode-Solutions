// Time:  O(logn)
// Space: O(1)

class Solution {
public:

    int maxSubArray(vector<int>& nums) {
      int max_num = nums[0];
      for(auto &i : nums){
        max_num = std::max(i, max_num);
      }
      if(max_num < 0)
        return max_num;
      int global_max = 0, local_max = 0;
      for(auto &x : nums){
        local_max = std::max(0, local_max + x);
        global_max = std::max(global_max, local_max);
      }
      return global_max;
    }
    
};
