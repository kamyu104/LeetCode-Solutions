# Time:  O(n)
# Space: O(1)

# stack
class Solution(object):
    def clearDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = []
        for x in s:
            if x.isdigit():
                result.pop()
                continue
            result.append(x)
        return "".join(result)
