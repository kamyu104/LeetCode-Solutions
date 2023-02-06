# Time:  O(n)
# Space: O(b)

# greedy
class Solution(object):
    def maxCount(self, banned, n, maxSum):
        """
        :type banned: List[int]
        :type n: int
        :type maxSum: int
        :rtype: int
        """
        lookup = set(banned)
        result = total = 0
        for i in xrange(1, n+1):
            if i in lookup:
                continue
            if total+i > maxSum:
                break
            total += i
            result += 1
        return result
