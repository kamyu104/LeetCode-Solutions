public  class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        int n = differences.length;
        int prefix = 0;
        int min = 0;
        int max = 0;
        int diff = upper-lower;
        
        for(int i = 0;i<n;i++){
            prefix = prefix + differences[i];
            min = Math.min(min,prefix);
            max = Math.max(max,prefix);
            if(max-min > diff) return 0;
        }
        return (diff) - (max -min) +1;
    }
} 
    

