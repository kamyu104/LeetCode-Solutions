# Time:  O(n * (logn)^(2*logn))
# Space: O(2*logn)

# backtracking
class Solution(object):
    def punishmentNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        def backtracking(curr, target):
            if target == 0:
                return curr == 0
            base = 10
            while curr >= base//10:
                q, r = divmod(curr, base)
                if target-r < 0:
                    break
                if backtracking(q, target-r):
                    return True
                base *= 10
            return False
    
        return sum(i**2 for i in xrange(1, n+1) if backtracking(i**2, i))
