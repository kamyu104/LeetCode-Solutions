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

# bit solution
class Solution(object):
    def pancakeSort(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        bit = BIT(len(arr))
        result = []
        for i in xrange(len(arr)):
            n = bit.query((arr[i]-1)-1)
            bit.add(arr[i]-1, 1)
            if n == i:  # already sorted
                continue
            if n == 0:                # (0..i-1)i
                if i > 1:
                    result.append(i)  # (i-1..0)i
                result.append(i+1)    # i(0..i-1)
            else:                     # (0..n-1)n(n+1..i-1)i
                if n > 1:
                    result.append(n)  # (n-1..0)n(n+1..i-1)i
                result.append(i)      # (i-1..n+1)n(0..n-1)i
                result.append(i+1)    # i(n-1..0)n(n+1..i-1)
                result.append(n+1)    # (0..n-1)in(n+1..i-1)
        return result


# Time:  O(nlogn)
# Space: O(n)
# merge sort solution
class Solution2(object):
    def pancakeSort(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
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
                if r <= mid:
                    tmp.append(idxs[i])
                counts[idxs[i][1]] += r - start
            while r <= mid:
                tmp.append(idxs[r])
                r += 1
            # Copy tmp back to idxs
            idxs[start:start+len(tmp)] = tmp
            
        idxs = []
        smaller_counts = [0]*len(arr)
        for i, x in enumerate(arr):
            idxs.append((x, i))
        smallerMergeSort(idxs, 0, len(idxs)-1, smaller_counts)
        result = []
        for i, n in enumerate(smaller_counts):
            if n == i:  # already sorted
                continue
            if n == 0:                # (0..i-1)i
                if i > 1:
                    result.append(i)  # (i-1..0)i
                result.append(i+1)    # i(0..i-1)
            else:                     # (0..n-1)n(n+1..i-1)i
                if n > 1:
                    result.append(n)  # (n-1..0)n(n+1..i-1)i
                result.append(i)      # (i-1..n+1)n(0..n-1)i
                result.append(i+1)    # i(n-1..0)n(n+1..i-1)
                result.append(n+1)    # (0..n-1)in(n+1..i-1)
        return result


# Time:  O(n^2)
# Space: O(1)
class Solution3(object):
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
