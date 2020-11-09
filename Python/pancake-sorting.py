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

class Solution(object):
    def pancakeSort(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        bit = BIT(len(arr))
        result = []
        bit.add(arr[0]-1, 1)
        for i in xrange(1, len(arr)):
            n = bit.query((arr[i]-1)-1)
            bit.add(arr[i]-1, 1)
            if n == i:
                continue
            if n == 0:
                if i > 1:
                    result.append(i)
                result.append(i+1)
            else:
                if n > 1:
                    result.append(n)
                result.append(i)
                result.append(i+1)
                result.append(n+1)
        return result


# Time:  O(n^2)
# Space: O(1)
class Solution2(object):
    def pancakeSort(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        def reverse(l, begin, end):
            for i in xrange((end-begin) // 2):
                l[begin+i], l[end-1-i] = l[end-1-i], l[begin+i]

        result = []
        for n in reversed(xrange(1, len(A)+1)):
            i = A.index(n)
            reverse(A, 0, i+1)
            result.append(i+1)
            reverse(A, 0, n)
            result.append(n)
        return result
