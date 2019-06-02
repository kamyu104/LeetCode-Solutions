# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def digitsCount(self, d, low, high):
        """
        :type d: int
        :type low: int
        :type high: int
        :rtype: int
        """
        def digitsCount(n, k):
            pivot, result = 1, 0
            while n >= pivot:
                result += (n//(10*pivot))*pivot + \
                           min(pivot, max(n%(10*pivot) - k*pivot + 1, 0))
                if k == 0:
                    result -= pivot
                pivot *= 10
            return result+1
        
        return digitsCount(high, d) - digitsCount(low-1, d)
