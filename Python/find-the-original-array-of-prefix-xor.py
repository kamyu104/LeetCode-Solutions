# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def findArray(self, pref):
        """
        :type pref: List[int]
        :rtype: List[int]
        """
        for i in reversed(xrange(1, len(pref))):
            pref[i] ^= pref[i-1]
        return pref
