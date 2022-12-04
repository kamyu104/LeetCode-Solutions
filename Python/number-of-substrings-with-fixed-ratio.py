# Time:  O(n)
# Space: O(n)

# freq table, prefix sum
class Solution(object):
    def fixedRatio(self, s, num1, num2):
        """
        :type s: str
        :type num1: int
        :type num2: int
        :rtype: int
        """
        lookup = collections.Counter()
        lookup[0] = 1
        result = curr = 0
        for c in s:
            curr += -num2 if c == '0' else +num1
            result += lookup[curr]
            lookup[curr] += 1
        return result
