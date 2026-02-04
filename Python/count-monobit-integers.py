# Time:  O(logn)
# Space: O(1)

# bitmasks
class Solution(object):
    def countMonobit(self, n):
        """
        :type n: int
        :rtype: int
        """
        return (n+1).bit_length()
