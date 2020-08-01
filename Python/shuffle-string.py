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
        result = map(ord, s)
        for i, c in enumerate(result):
            if c < 0:
                continue
            move, j = -c, indices[i]
            while j != i:
                result[j], move = move, result[j]
                move, j = -move, indices[j]
            result[i] = move
        return "".join(map(lambda x: chr(-x), result))


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
