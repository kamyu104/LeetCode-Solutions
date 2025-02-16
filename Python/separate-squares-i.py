# Time:  O(nlogr)
# Space: O(1)

# binary search
class Solution(object):
    def separateSquares(self, squares):
        """
        :type squares: List[List[int]]
        :rtype: float
        """
        EPS = 1e-5
        def binary_search(left, right, check):
            while right-left > EPS:
                mid = left+(right-left)/2.0
                if check(mid):
                    right = mid
                else:
                    left = mid
            return left
    
        def check(k):
            result = 0
            for x, y, l in squares:
                if y >= k:
                    result += l**2
                elif y+l <= k:
                    result -= l**2
                else:
                    result += l*(((y+l)-k)-(k-y))
            return result <= 0
    
        return binary_search(min(y for _, y, _ in squares), max(y+l for _, y, l in squares), check)
