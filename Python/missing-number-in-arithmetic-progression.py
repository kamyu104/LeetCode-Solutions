# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def missingNumber(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        def check(arr, d, x):
            return arr[x] != arr[0] + d*x

        d = (arr[-1]-arr[0])//len(arr)
        left, right = 0, len(arr)-1
        while left <= right:
            mid = left + (right-left)//2
            if check(arr, d, mid):
                right = mid-1
            else:
                left = mid+1
        return arr[0] + d*left


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def missingNumber(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        return (min(arr)+max(arr))*(len(arr)+1)//2 - sum(arr)
