# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def maxNumberOfApples(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        LIMIT = 5000
        arr.sort()
        result, total = 0, 0
        for x in arr:
            if total+x > LIMIT:
                break
            total += x
            result += 1
        return result
