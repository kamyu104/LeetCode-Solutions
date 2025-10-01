class Solution:
    def minimumTotal(self, t: List[List[int]]) -> int:
        n=len(t)
        for i in range(1, n):
            t[i][0]+=t[i-1][0]
            t[i][i]+=t[i-1][i-1]
            for j in range(1, i):
                t[i][j]+=min(t[i-1][j], t[i-1][j-1])
        return min(t[-1])
        
