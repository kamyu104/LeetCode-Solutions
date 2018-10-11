# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def search(self, reader, target):
        """
        :type reader: ArrayReader
        :type target: int
        :rtype: int
        """
        left, right = 0, 19999
        while left <= right:
            mid = left + (right-left)//2
            response = reader.get(mid)
            if response > target:
                right = mid-1
            elif response < target:
                left = mid+1
            else:
                return mid
        return -1

