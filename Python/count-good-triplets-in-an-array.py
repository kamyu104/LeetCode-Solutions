# Time:  O(nlogn)
# Space: O(n)

class BIT(object):  # 0-indexed.
    def __init__(self, n):
        self.__bit = [0]*(n+1)  # Extra one for dummy node.

    def add(self, i, val):
        i += 1  # Extra one for dummy node.
        while i < len(self.__bit):
            self.__bit[i] += val
            i += (i & -i)

    def query(self, i):
        i += 1  # Extra one for dummy node.
        ret = 0
        while i > 0:
            ret += self.__bit[i]
            i -= (i & -i)
        return ret


# bit, fenwick tree, combinatorics
class Solution(object):
    def goodTriplets(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        lookup = [0]*len(nums1)
        for i, x in enumerate(nums1):
            lookup[x] = i
        result = 0
        bit = BIT(len(nums1))
        for i, x in enumerate(nums2):
            smaller = bit.query(lookup[x]-1)
            larger = (len(nums1)-(lookup[x]+1))-(i-smaller)
            result += smaller*larger
            bit.add(lookup[x], 1)
        return result
