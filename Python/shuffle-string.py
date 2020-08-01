# Time:  O(n)
# Space: O(1)

# in-place solution
class Solution(object):
    def restoreString(self, s, indices):
        """
        :type s: str
        :type indices: List[int]
        :rtype: str
        """
        result = list(s)
        for i, c in enumerate(result):
            if indices[i] == i:
                continue
            move, j = c, indices[i]
            while j != i:
                result[j], move = move, result[j]
                indices[j], j = j, indices[j]
            result[i] = move
        return "".join(result)


# Time:  O(n)
# Space: O(1)
import itertools


class Solution2(object):
    def restoreString(self, s, indices):
        """
        :type s: str
        :type indices: List[int]
        :rtype: str
        """
        result = ['']*len(s)
        for i, c in itertools.izip(indices, s):
            result[i] = c
        return "".join(result)
