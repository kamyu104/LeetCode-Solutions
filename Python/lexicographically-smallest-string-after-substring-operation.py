# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def smallestString(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = list(s)
        i = next((i for i in xrange(len(s)) if s[i] != 'a'), len(s))
        if i == len(s):
            result[-1] = 'z'
        else:
            for i in xrange(i, len(s)):
                if result[i] == 'a':
                    break
                result[i] = chr(ord(result[i])-1)
        return "".join(result)
