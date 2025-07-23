/*Problem Statement: Given an integer array arr of size N, sorted in ascending order
(with distinct values). Now the array is rotated between 1 to N times which is unknown.
 Find the minimum element in the array.
 */

class Solution {
    public int findMin(int[] nums) {
        int n =nums.length;
        int l=0;
        int h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]>nums[h])
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return nums[l];
    }
}