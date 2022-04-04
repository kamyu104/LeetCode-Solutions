# Time:  O(nlogr), r is max(candies)
# Space: O(1)

# binary search
class Solution(object):
    def maximumCandies(self, candies, k):
        """
        :type candies: List[int]
        :type k: int
        :rtype: int
        """
        def check(x):
            return sum(c//x for c in candies) >= k

        left, right = 1, max(candies)
        while left <= right:
            mid = left+(right-left)//2
            if not check(mid):
                right = mid-1
            else:
                left = mid+1
        return right
