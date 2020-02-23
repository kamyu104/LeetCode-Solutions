# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def sortByBits(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        def popcount(n):  # Time: O(logn) ~= O(1) if n is a 32-bit number
            result = 0
            while n:
                n &= n - 1
                result += 1
            return result
        
        arr.sort(key=lambda x: (popcount(x), x))
        return arr
