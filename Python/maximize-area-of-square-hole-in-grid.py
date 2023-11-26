# Time:  O(h + v), h = len(hBars), v = len(vBars)
# Space: O(h + v)

# array, hash table
class Solution(object):
    def maximizeSquareHoleArea(self, n, m, hBars, vBars):
        """
        :type n: int
        :type m: int
        :type hBars: List[int]
        :type vBars: List[int]
        :rtype: int
        """
        def max_gap(arr):
            result = l = 1
            lookup = set(arr)
            while lookup:
                x = next(iter(lookup))
                left = x
                while left-1 in lookup:
                    left -= 1
                right = x
                while right+1 in lookup:
                    right += 1
                for i in xrange(left, right+1):
                    lookup.remove(i)
                result = max(result, (right-left+1)+1)
            return result

        return min(max_gap(hBars), max_gap(vBars))**2


# Time:  O(hlogh + vlogv), h = len(hBars), v = len(vBars)
# Space: O(1)
# array, sort
class Solution2(object):
    def maximizeSquareHoleArea(self, n, m, hBars, vBars):
        """
        :type n: int
        :type m: int
        :type hBars: List[int]
        :type vBars: List[int]
        :rtype: int
        """
        def max_gap(arr):
            arr.sort()
            result = l = 1
            for i in xrange(len(arr)):
                l += 1
                result = max(result, l)
                if i+1 != len(arr) and arr[i+1] != arr[i]+1:
                    l = 1
            return result

        return min(max_gap(hBars), max_gap(vBars))**2
