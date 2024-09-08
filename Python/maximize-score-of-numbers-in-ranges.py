# Time:  O(nlogn + nlogr) = O(nlogr)
# Space: O(1)

# binary search, greedy
class Solution(object):
    def maxPossibleScore(self, start, d):
        """
        :type start: List[int]
        :type d: int
        :rtype: int
        """
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right
    
        def check(x):
            curr = float("-inf")
            for i in start:
                curr = max(curr+x, i)
                if curr > i+d:
                    return False
            return True

        start.sort()
        return binary_search_right(1, start[-1]+d-start[0], check)
