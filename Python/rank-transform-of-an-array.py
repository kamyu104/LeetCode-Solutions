# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def arrayRankTransform(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        return map({x: i+1 for i, x in enumerate(sorted(set(arr)))}.get, arr)
