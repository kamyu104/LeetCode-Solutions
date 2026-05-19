# Time:  O(logr * logk)
# Space: O(1)

# binary search, fast exponentiation
class Solution(object):
    def countKthRoots(self, l, r, k):
        """
        :type l: int
        :type r: int
        :type k: int
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

        def count(right):
            return binary_search_right(0, right, lambda x: x**k <= right)-0+1
        
        return count(r)-count(l-1)
