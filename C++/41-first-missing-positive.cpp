//Problem Link : https://leetcode.com/problems/first-missing-positive/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=1;i<=nums.size()+1;i++){
            int d=count(nums.begin(),nums.end(),i);
            if(d==0) return i;
        }
        return 0;
    }
};