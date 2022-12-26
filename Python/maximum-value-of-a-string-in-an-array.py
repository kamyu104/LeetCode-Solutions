# Time:  O(n * l)
# Space: O(1)

# string
class Solution(object):
    def maximumValue(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        return max(int(s) if s.isdigit() else len(s) for s in strs)
