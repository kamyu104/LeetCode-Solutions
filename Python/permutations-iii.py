# Time:  O(n * n!)
# Space: O(n)

# backtracking, bitmasks
class Solution(object):
    def permute(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        def backtracking(lookup):
            if len(curr) == n:
                result.append(curr[:])
                return
            for i in xrange(1, n+1):
                if lookup&(1<<(i-1)) or (curr and curr[-1]%2 == i%2):
                    continue
                curr.append(i)
                backtracking(lookup^(1<<(i-1)))
                curr.pop()
    
        result, curr = [], []
        backtracking(0)
        return result
