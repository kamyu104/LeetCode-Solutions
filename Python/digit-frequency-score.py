# Time:  O(logn)
# Space: O(1)

# freq table
class Solution(object):
    def digitFrequencyScore(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt = [0]*10
        while n:
            n, r = divmod(n, 10)
            cnt[r] += 1
        return sum(i*x for i, x in enumerate(cnt))
