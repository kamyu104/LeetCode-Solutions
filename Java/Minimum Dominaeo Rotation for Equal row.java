class Solution 
{
    public int minDominoRotations(int[] tops, int[] bottoms) 
    {
        // Step 1: Try to make all values equal to tops[0]
        int result = check(tops[0], tops, bottoms);

        // Step 2: If tops[0] failed, try bottoms[0]
        if (result != -1) return result;

        // Step 3: Return result from checking bottoms[0]
        return check(bottoms[0], tops, bottoms);
    }

    // Step 4: Helper function to count rotations to make all values = target
    private int check(int target, int[] tops, int[] bottoms) 
    {
        int rotateTop = 0;    // Rotations needed to bring target to top
        int rotateBottom = 0; // Rotations needed to bring target to bottom

        // Step 5: Loop through all dominoes
        for (int i = 0; i < tops.length; i++) 
        {
            // Step 6: If target is not on either side, it's impossible
            if (tops[i] != target && bottoms[i] != target) 
            {
                return -1;
            }

            // Step 7: If top doesn't have the target, it must be rotated
            if (tops[i] != target)
            {
                rotateTop++;
            } 

            // Step 8: If bottom doesn't have the target, it must be rotated
            if (bottoms[i] != target)
            {
                rotateBottom++;
            } 
        }

        // Step 9: Return the minimum of the two rotation counts
        return Math.min(rotateTop, rotateBottom);
    }
}
    