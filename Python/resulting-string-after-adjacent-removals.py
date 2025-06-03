# Time:  O(n)
# Space: O(1)

# simulation, stack
class Solution(object):
    def resultingString(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = []
        for x in s:
            if result:
                diff = abs(ord(x)-ord(result[-1]))
                if diff in (1, 25):
                    result.pop()
                    continue
            result.append(x)
        return "".join(result)
