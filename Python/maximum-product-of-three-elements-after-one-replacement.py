# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        L = 2
        top = [0]*L
        for x in nums:
            x = abs(x)
            for i in xrange(L):
                if x > top[i]:
                    x, top[i] = top[i], x
        return top[0]*top[1]*10**5
