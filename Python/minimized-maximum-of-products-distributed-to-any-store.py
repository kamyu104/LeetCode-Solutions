# Time:  O(nlogm), m is the max of quantities
# Space: O(1)

class Solution(object):
    def minimizedMaximum(self, n, quantities):
        """
        :type n: int
        :type quantities: List[int]
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+(b-1))//b

        def check(n, quantities, x):
            return sum(ceil_divide(q, x) for q in quantities) <= n
         
        left, right = 1, max(quantities)
        while left <= right:
            mid = left+(right-left)//2
            if check(n, quantities, mid):
                right = mid-1
            else:
                left = mid+1
        return left
