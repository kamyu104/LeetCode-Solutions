# Time:  O(n)
# Space: O(1)

class Solution(object):
    def restoreString(self, s, indices):
        """
        :type s: str
        :type indices: List[int]
        :rtype: str
        """
        result = ['']*len(s)
        for i, c in enumerate(s):
            result[indices[i]] = c
        return "".join(result)
