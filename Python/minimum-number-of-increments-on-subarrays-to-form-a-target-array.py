# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minNumberOperations(self, target):
        """
        :type target: List[int]
        :rtype: int
        """
        return target[0]+sum(max(target[i]-target[i-1], 0) for i in xrange(1, len(target)))


# Time:  O(n)
# Space: O(n)
import itertools


class Solution2(object):
    def minNumberOperations(self, target):
        """
        :type target: List[int]
        :rtype: int
        """
        return sum(max(b-a, 0) for b, a in itertools.izip(target, [0]+target))
