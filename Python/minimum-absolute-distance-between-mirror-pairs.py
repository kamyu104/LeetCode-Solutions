# Time:  O(nlogr)
# Space: O(n)

# hash table
class Solution(object):
    def minMirrorPairDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        INF = float("inf")
        def reverse(n):
            result = 0
            while n:
                result = result*10+n%10
                n //= 10
            return result

        result = INF
        lookup = {}
        for i, x in enumerate(nums):
            if x in lookup:
                result = min(result, i-lookup[x])
            lookup[reverse(x)] = i
        return result if result is not INF else -1
