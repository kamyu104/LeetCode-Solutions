# Time:  O(n * logr * logn)
# Space: O(nlogr)

# sort
class Solution(object):
    def maxGoodNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return int("".join(sorted(map(lambda x: bin(x)[2:], nums), cmp=lambda x, y: (x+y > y+x)-(x+y < y+x), reverse=True)), 2)


# Time:  O(n! * nlogr)
# Space: O(nlogr)
import itertools


# brute force
class Solution2(object):
    def maxGoodNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return max(int("".join(x), 2) for x in itertools.permutations(map(lambda x: bin(x)[2:], nums)))
