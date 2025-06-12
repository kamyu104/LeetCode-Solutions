class Solution {

    // update RGB combination as 0x7 for improvement.
        
    private static final int R = 1;
    private static final int G = 2;
    private static final int B = 4;
    private static final int mod = (int)1e9+7;   
    public int colorTheGrid(int m, int n) {

        //compute overall number of possible permutations for a single column
        int count = 3;
        for(int i = 0; i  < m - 1; i++)
            count *= 2;
        
        long[] perms = new long[count];
        Queue<Integer> que = new LinkedList<>();
                
        que.offer(R);
        que.offer(G);
        que.offer(B);
        
        //fill in all possible permuatations using Queue
        int index = count;
        
        while(!que.isEmpty()){
            int color  = que.poll();
            if( color >=  1 << 3 * (m-1) ) //m - length permutation
                perms[--index] = color;
            else{
                
                   int nextcolors = 0x7^ (color & 0x7);
                   while(nextcolors > 0){
                       int nextcolor = nextcolors &(-nextcolors);
                       que.add((color << 3) + nextcolor);
                       nextcolors &= (nextcolors - 1);
                    }
                }
        }
        
        int[] cur = new int[count];
        Arrays.fill(cur, 1);
        
        //iterate by columns from left to right, 
        //memorizing score count for every permutation in current column
        for(int col = 0; col < n-1; col++){
            
            int[] next = new int[count];

            for(int i = 0; i < count; i++){
                for(int j = 0; j < count; j++){
                    if((perms[i] & perms[j]) == 0) // both are OK to each other 
                        next[j] = (next[j] + cur[i])%mod;
                }
            }
            cur = next;
        }
        
        //accumulate all scores for permuttions as per last column 
        int result = 0;
        for(int i = 0; i < count; i++)
            result = (result + cur[i]) % mod;
        
        return result;    
    }
}