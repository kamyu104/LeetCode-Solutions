# Time:  O(nlogm)
# Space: O(m)

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
    def createSortedArray(self, instructions):
        """
        :type instructions: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        bit = BIT(max(instructions))
        result = 0
        for i, inst in enumerate(instructions):
            inst -= 1
            result += min(bit.query(inst-1), i-bit.query(inst))
            bit.add(inst, 1)
        return result % MOD


# Time:  O(nlogn)
# Space: O(n)
import itertools
class Solution_TLE(object):
    def createSortedArray(self, instructions):
        """
        :type instructions: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        def smallerMergeSort(idxs, start, end, counts):
            if end - start <= 0:  # The size of range [start, end] less than 2 is always with count 0.
                return 0

            mid = start + (end - start) // 2
            smallerMergeSort(idxs, start, mid, counts)
            smallerMergeSort(idxs, mid + 1, end, counts)
            r = start
            tmp = []
            for i in xrange(mid+1, end + 1):
                # Merge the two sorted arrays into tmp.
                while r <= mid and idxs[r][0] < idxs[i][0]:
                    tmp.append(idxs[r])
                    r += 1
                tmp.append(idxs[i])
                counts[idxs[i][1]] += r - start
            while r <= mid:
                tmp.append(idxs[r])
                r += 1
            # Copy tmp back to idxs
            idxs[start:start+len(tmp)] = tmp
        
        def largerMergeSort(idxs, start, end, counts):
            if end - start <= 0:  # The size of range [start, end] less than 2 is always with count 0.
                return 0

            mid = start + (end - start) // 2
            largerMergeSort(idxs, start, mid, counts)
            largerMergeSort(idxs, mid + 1, end, counts)
            r = start
            tmp = []
            for i in xrange(mid+1, end + 1):
                # Merge the two sorted arrays into tmp.
                while r <= mid and idxs[r][0] <= idxs[i][0]:
                    tmp.append(idxs[r])
                    r += 1
                if r <= mid:
                    tmp.append(idxs[i])
                counts[idxs[i][1]] += mid - r + 1
            while r <= mid:
                tmp.append(idxs[r])
                r += 1
            # Copy tmp back to idxs
            idxs[start:start+len(tmp)] = tmp

        idxs = []
        smaller_counts, larger_counts = [[0] * len(instructions) for _ in xrange(2)]
        for i, inst in enumerate(instructions):
            idxs.append((inst, i))
        smallerMergeSort(idxs[:], 0, len(idxs)-1, smaller_counts)
        largerMergeSort(idxs, 0, len(idxs)-1, larger_counts)
        return sum(min(s, l) for s, l in itertools.izip(smaller_counts, larger_counts)) % MOD
