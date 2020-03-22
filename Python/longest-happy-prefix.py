# Time:  O(n)
# Space: O(n)

# kmp solution
class Solution(object):
    def longestPrefix(self, s):
        """
        :type s: str
        :rtype: str
        """
        def getPrefix(pattern):
            prefix = [-1]*len(pattern)
            j = -1
            for i in xrange(1, len(pattern)):
                while j != -1 and pattern[j+1] != pattern[i]:
                    j = prefix[j]
                if pattern[j+1] == pattern[i]:
                    j += 1
                prefix[i] = j
            return prefix
        
        return s[:getPrefix(s)[-1]+1]


# Time:  O(n) on average
# Space: O(1)
# rolling-hash solution
class Solution2(object):
    def longestPrefix(self, s):
        """
        :type s: str
        :rtype: str
        """
        M = 10**9+7
        D = 26
        def check(l, s):
            for i in xrange(l):
                if s[i] != s[len(s)-l+i]:
                    return False
            return True
    
        result, prefix, suffix, power = 0, 0, 0, 1
        for i in xrange(len(s)-1):
            prefix = (prefix*D + (ord(s[i])-ord('a'))) % M
            suffix = (suffix + (ord(s[len(s)-(i+1)])-ord('a'))*power) % M
            power = (power*D)%M
            if prefix == suffix:
                # we assume M is a very large prime without hash collision
                # assert(check(i+1, s))
                result = i+1
        return s[:result]
