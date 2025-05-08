public class Solution 
{
    public int countSubarrays(int[] nums) 
    {
        int count = 0;
        
        // Step 1: Loop through the array to check subarrays of size 3
        for (int i = 0; i <= nums.length - 3; i++) 
        {
            // Step 2: Extract the three consecutive elements
            int first = nums[i];
            int second = nums[i + 1];
            int third = nums[i + 2];
            
            // Step 3: Check if 2 * (first + third) == second
            if (2 * (first + third) == second) 
            {
                count++; // Increment count if condition is satisfied
            }
        }
        
        // Step 4: Return the final count of subarrays that satisfy the condition
        return count;
        //he.ll
    }

} 
