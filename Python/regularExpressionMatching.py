# Time:  O(m * n)
# Space: O(n)
#
# Implement regular expression matching with support for '.' and '*'.
# 
# '.' Matches any single character.
# '*' Matches zero or more of the preceding element.
# 
# The matching should cover the entire input string (not partial).
# 
# The function prototype should be:
# bool isMatch(const char *s, const char *p)
# 
# Some examples:
# isMatch("aa","a") -> false
# isMatch("aa","aa") -> true
# isMatch("aaa","aa") -> false
# isMatch("aa", "a*") -> true
# isMatch("aa", ".*") -> true
# isMatch("ab", ".*") -> true
# isMatch("aab", "c*a*b") -> true
#

# dp
class Solution:
    # @return a boolean
    def isMatch(self, s, p):
        k = 3
        result = [[False for j in xrange(len(p) + 1)] for i in xrange(k)]
        
        result[0][0] = True
        for i in xrange(2, len(p) + 1):
            if p[i-1] == '*':
                result[0][i] = result[0][i-2]
        
        for i in xrange(1,len(s) + 1):
            if i > 1:
                result[0][0] = False
            for j in xrange(1, len(p) + 1):
                if p[j-1] != '*':
                    result[i % k][j] = result[(i-1) % k][j-1] and (s[i-1] == p[j-1] or p[j-1] == '.')
                else:
                    result[i % k][j] = result[i % k][j-2] or (result[(i-1) % k][j] and (s[i-1] == p[j-2] or p[j-2]=='.'))
                    
        return result[len(s) % k][len(p)]

# dp
# Time:  O(m * n)
# Space: O(m * n)
class Solution2:
    # @return a boolean
    def isMatch(self, s, p):
        result = [[False for j in xrange(len(p) + 1)] for i in xrange(len(s) + 1)]
        
        result[0][0] = True
        for i in xrange(2, len(p) + 1):
            if p[i-1] == '*':
                result[0][i] = result[0][i-2]
                    
        for i in xrange(1,len(s) + 1):
            for j in xrange(1, len(p) + 1):
                if p[j-1] != '*':
                    result[i][j] = result[i-1][j-1] and (s[i-1] == p[j-1] or p[j-1] == '.')
                else:
                    result[i][j] = result[i][j-2] or (result[i-1][j] and (s[i-1] == p[j-2] or p[j-2]=='.'))
                    
        return result[len(s)][len(p)]

# recursive
class Solution3:
    # @return a boolean
    def isMatch(self, s, p):
        if len(p) == 0:
            return len(s) == 0
        
        if len(p) == 1 or p[1] != '*':
            if len(s) == 0 or (p[0] == s[0] or p[0] == '.'):
                return self.isMatch(s[1:], p[1:])
            else:
                return False
        else:
            while len(s) > 0 and (p[0] == s[0] or p[0] == '.'):
                if self.isMatch(s, p[2:]):
                    return True
                s = s[1:]
            return self.isMatch(s, p[2:])

if __name__ == "__main__":
    print Solution().isMatch("abcd","d*")
    print Solution().isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c")
    print Solution().isMatch("aa","a")
    print Solution().isMatch("aa","aa")
    print Solution().isMatch("aaa","aa")
    print Solution().isMatch("aa", "a*")
    print Solution().isMatch("aa", ".*")
    print Solution().isMatch("ab", ".*")
    print Solution().isMatch("aab", "c*a*b")