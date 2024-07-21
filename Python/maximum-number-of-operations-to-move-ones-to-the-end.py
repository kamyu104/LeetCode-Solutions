# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maxOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = curr = 0
        for i in xrange(len(s)):
            if s[i] == '1':
                curr += 1
            elif i+1 == len(s) or s[i+1] == '1':
                result += curr
        return result


# Time:  O(n)
# Space: O(1)
# greedy
class Solution2(object):
    def maxOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = curr = 0
        for i in xrange(len(s)):
            if s[i] != '1':
                continue
            curr += 1
            if i+1 < len(s) and s[i+1] == '0':
                result += curr
        return result
