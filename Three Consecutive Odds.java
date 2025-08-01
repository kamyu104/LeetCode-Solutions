class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        // Loop through the array up to the third-to-last element
        for (int i = 0; i < arr.length - 2; i++) {
            // Check if the current element and the next two elements are all odd
            int product=arr[i]*arr[i+1]*arr[i+2];
            if(product% 2==1){
                return true;
            }
        }

        return false;
    }
}
