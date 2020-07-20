# Time:  O(nlogm), m is the max value of arr
# Space: O(logm)

class Solution(object):
    def closestToTarget(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
        result, dp = float("inf"), set()  # at most O(logm) dp states
        for x in arr:
            dp = {x}|{f&x for f in dp}
            for f in dp:
                result = min(result, abs(f-target))
        return result
