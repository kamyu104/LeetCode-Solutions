# Time:  O(nlogn + nlogr), r = max(e for _, e in tasks)
# Space: O(r)

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


# sort, greedy, bit, fenwick tree
class Solution(object):
    def findMinimumTime(self, tasks):
        """
        :type tasks: List[List[int]]
        :rtype: int
        """
        tasks.sort(key=lambda x: x[1])
        bit = BIT(tasks[-1][1]+1)
        for s, e, d in tasks:
            d -= bit.query(e)-bit.query(s-1)
            for i in reversed(xrange(1, e+1)):
                if d <= 0:
                    break
                if bit.query(i)-bit.query(i-1):
                    continue
                bit.add(i, 1)
                d -= 1
        return bit.query(tasks[-1][1])
