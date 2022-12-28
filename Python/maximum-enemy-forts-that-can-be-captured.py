# Time:  O(n)
# Space: O(1)

# array, two pointers
class Solution(object):
    def captureForts(self, forts):
        """
        :type forts: List[int]
        :rtype: int
        """
        result = left = 0
        for right in xrange(len(forts)):
            if not forts[right]:
                continue
            if forts[right] == -forts[left]:
                result = max(result, right-left-1)
            left = right
        return result
