class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftbound=0, rightbound=height.size()-1;
        int currArea,maxWater=0;
        int wt,ht;
        while(leftbound<rightbound)
        {
          wt=rightbound-leftbound;
          ht=min(height[leftbound],height[rightbound]);
          currArea=wt*ht;
          maxWater=max(maxWater,currArea);
          height[leftbound]<height[rightbound]?leftbound++:rightbound--;
        }
        return maxWater;
    }
};
