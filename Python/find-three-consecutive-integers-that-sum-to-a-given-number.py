# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def sumOfThree(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        return [num//3-1, num//3, num//3+1] if num%3 == 0 else []
