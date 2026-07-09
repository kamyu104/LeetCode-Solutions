/******************************************************************************
189.) Rotate Array 
Difficulty: Medium
Description: Given an array, rotate the array to the right by k steps, where k is non-negative.

Naive Approach: Create a function that rotates the array onces, then rotate the array k times.
Efficient Approach: Reverse the whole list, then reverse the first k elements, and the last n - k elements. 
*******************************************************************************/

public class RotateArray
{
	public static void main(String[] args) {
    
		/* This is the test, expected output is [4,5,1,2,3] */
    
		int [] arr = {1,2,3,4,5};
		
		rotate(arr, 2);
		
		int[] rotate_arr = arr;
		
		for(int i = 0; i < rotate_arr.length; i++){
		    System.out.print(rotate_arr[i] + " ");
		}
		
	}
	
	 public static void rotate(int[] nums, int k) {
        k = k % nums.length;
        
        
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.length - 1); 
    }
    
    public static int [] reverse(int [] nums, int start, int end){
        int indx_end = end, indx_start = start;
        
        while(indx_start < indx_end){
            int temp = nums[indx_start];
            nums[indx_start] = nums[indx_end];
            nums[indx_end] = temp;
            indx_start++;
            indx_end--;
            
            }
        
        return nums;
       
    }
}



