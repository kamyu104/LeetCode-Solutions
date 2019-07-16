# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        lookup = {v: i for i, v in enumerate(arr2)}
        return sorted(arr1, key=lambda i: lookup.get(i, len(arr2)+i))
