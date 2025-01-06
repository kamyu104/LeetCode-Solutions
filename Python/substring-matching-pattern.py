# Time:  O(n + m)
# Space: O(m)

# kmp 
class Solution(object):
    def hasMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        def getPrefix(pattern):
            prefix = [-1]*len(pattern)
            j = -1
            for i in xrange(1, len(pattern)):
                while j+1 > 0 and pattern[j+1] != pattern[i]:
                    j = prefix[j]
                if pattern[j+1] == pattern[i]:
                    j += 1
                prefix[i] = j
            return prefix

        def KMP(text, pattern, i):
            prefix = getPrefix(pattern)
            j = -1
            for i in xrange(i, len(text)):
                while j+1 > 0 and pattern[j+1] != text[i]:
                    j = prefix[j]
                if pattern[j+1] == text[i]:
                    j += 1
                if j+1 == len(pattern):
                    return i-j
            return -1

        i = 0
        for x in p.split('*'):
            if not x:
                continue
            i = KMP(s, x, i)
            if i == -1:
                return False
            i += len(x)
        return True
  
