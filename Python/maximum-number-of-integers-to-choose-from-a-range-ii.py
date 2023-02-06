# Time:  O(blogb + logn * logb)
# Space: O(b)

import bisect


# binary search, prefix sum
class Solution(object):
    def maxCount(self, banned, n, maxSum):
        """
        :type banned: List[int]
        :type n: int
        :type maxSum: int
        :rtype: int
        """
        def check(x):
            return (x+1)*x//2-prefix[bisect.bisect_right(banned, x)] <= maxSum
    
        banned.sort()
        prefix = [0]*(len(banned)+1)
        for i in xrange(len(banned)):
            prefix[i+1] = prefix[i]+banned[i]
        left, right = 1, n
        while left <= right:
            mid = left + (right-left)//2
            if not check(mid):
                right = mid-1
            else:
                left = mid+1
        return right-bisect.bisect_right(banned, right)
