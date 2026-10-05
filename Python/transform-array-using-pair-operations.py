# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def canTransform(self, source, target):
        """
        :type source: List[int]
        :type target: List[int]
        :rtype: bool
        """
        return sum(source) == sum(target)
