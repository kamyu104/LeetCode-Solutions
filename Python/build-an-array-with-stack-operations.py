# Time:  O(n)
# Space: O(1)

class Solution(object):
    def buildArray(self, target, n):
        """
        :type target: List[int]
        :type n: int
        :rtype: List[str]
        """
        result, curr = [], 1
        for t in target:
            result.extend(["Push", "Pop"]*(t-curr))
            result.append("Push")
            curr = t+1
        return result
