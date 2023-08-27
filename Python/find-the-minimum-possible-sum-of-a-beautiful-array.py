class Solution(object):
    def minimumPossibleSum(self, n, target):
        """
        :type n: int
        :type target: int
        :rtype: int
        """
        def arithmetic_progression_sum(a, d, n):
            return (a+(a+(n-1)*d))*n//2
    
        a = min(target//2, n)
        b = n-a
        return arithmetic_progression_sum(1, 1, a)+arithmetic_progression_sum(target, 1, b)
    
