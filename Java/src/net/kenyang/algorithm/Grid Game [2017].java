class Solution {
    public long gridGame(int[][] a) {
        int n=a[0].length;
        long top=0,bot=0;
        long ans=Long.MAX_VALUE;
        for(int i=0;i<n;i++) top+=a[0][i];
        for(int i=0;i<n;i++)
        {
            top-=a[0][i];
            ans=Math.min(ans,Math.max(top,bot));
            bot+=a[1][i];
        }
        return ans;
    }
}
