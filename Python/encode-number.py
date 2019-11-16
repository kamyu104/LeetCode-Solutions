# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def encode(self, num):
        """
        :type num: int
        :rtype: str
        """
        result = []
        while num:
            result.append('0' if num%2 else '1')
            num = (num-1)//2
        return "".join(reversed(result))
