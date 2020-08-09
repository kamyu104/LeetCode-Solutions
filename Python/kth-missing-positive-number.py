# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def findKthPositive(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        def check(arr, k, x):
            return arr[x]-(x+1) < k

        left, right = 0, len(arr)-1
        while left <= right:
            mid = left + (right-left)//2
            if not check(arr, k, mid):
                right = mid-1
            else:
                left = mid+1
        return right+1+k  # arr[right] + (k-(arr[right]-(right+1))) if right >= 0 else k
