# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def findTheDistanceValue(self, arr1, arr2, d):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :type d: int
        :rtype: int
        """
        arr1.sort(), arr2.sort()
        result, i, j = 0, 0, 0
        while i < len(arr1) and j < len(arr2):
            if arr1[i]-arr2[j] > d:
                j += 1
                continue
            result += arr2[j]-arr1[i] > d
            i += 1
        return result+len(arr1)-i
