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
            for j in xrange(i, len(s)):
                if result[j] == 'a':
                    break
                result[j] = chr(ord('a')+(ord(s[j])-ord('a'))-1)
        return "".join(result)
