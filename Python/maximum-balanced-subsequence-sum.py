# Time:  O(nlogn)
# Space: O(n)

from sortedcontainers import SortedList


# sorted list, binary search, mono stack
class Solution(object):
    def maxBalancedSubsequenceSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        NEG_INF = float("-inf")
        def query(sl, k):
            j = sl.bisect_left((k,))
            return sl[j-1][1] if j-1 >= 0 else NEG_INF
    
        def update(sl, k, v):
            j = sl.bisect_left((k,))
            if j < len(sl) and sl[j][0] == k:
                if not (sl[j][1] < v):
                    return
                del sl[j]
            elif not (j-1 < 0 or sl[j-1][1] < v):
                return
            sl.add((k, v))
            while j+1 < len(sl) and sl[j+1][1] <= sl[j][1]:
                del sl[j+1]

        result = NEG_INF
        sl = SortedList()
        for i, x in enumerate(nums):
            v = max(query(sl, (x-i)+1), 0)+x
            result = max(result, v)
            update(sl, x-i, v)
        return result


# Time:  O(nlogn)
# Space: O(n)
# bit, fenwick tree
class Solution2(object):
    def maxBalancedSubsequenceSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        NEG_INF = float("-inf")
        class BIT(object):  # 0-indexed.
            def __init__(self, n, default=0, fn=lambda x, y: x+y):
                self.__bit = [NEG_INF]*(n+1)  # Extra one for dummy node.
                self.__default = default
                self.__fn = fn

            def update(self, i, val):
                i += 1  # Extra one for dummy node.
                while i < len(self.__bit):
                    self.__bit[i] = self.__fn(self.__bit[i], val)
                    i += (i & -i)

            def query(self, i):
                i += 1  # Extra one for dummy node.
                ret = self.__default
                while i > 0:
                    ret = self.__fn(ret, self.__bit[i])
                    i -= (i & -i)
                return ret

        val_to_idx = {x:i for i, x in enumerate(sorted({x-i for i, x in enumerate(nums)}))}
        result = NEG_INF
        bit = BIT(len(val_to_idx), default=NEG_INF, fn=max)
        for i, x in enumerate(nums):
            v = max(bit.query(val_to_idx[x-i]), 0)+x
            result = max(result, v)
            bit.update(val_to_idx[x-i], v)
        return result
