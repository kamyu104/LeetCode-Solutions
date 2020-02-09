# Time:  O(n)
# Space: O(n)

class Solution(object):
    def checkIfExist(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        lookup = set()
        for x in arr:
            if 2*x in lookup or \
               (x%2 == 0 and x//2 in lookup):
                return True
            lookup.add(x)
        return False
