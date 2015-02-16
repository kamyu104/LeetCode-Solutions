# Time:  O(m + n)
# Space: O(1)
#
# Implement wildcard pattern matching with support for '?' and '*'.
# 
# '?' Matches any single character.
# '*' Matches any sequence of characters (including the empty sequence).
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
# isMatch("aa", "*") -> true
# isMatch("aa", "a*") -> true
# isMatch("ab", "?*") -> true
# isMatch("aab", "c*a*b") -> false
#

# iteration
class Solution:
    # @param s, an input string
    # @param p, a pattern string
    # @return a boolean
    def isMatch(self, s, p):
        p_ptr, s_ptr, last_s_ptr, last_p_ptr = 0, 0, -1, -1
        while s_ptr < len(s):
            if p_ptr < len(p) and (s[s_ptr] == p[p_ptr] or p[p_ptr] == '?'):
                s_ptr += 1
                p_ptr += 1
            elif p_ptr < len(p) and p[p_ptr] == '*':
                p_ptr += 1
                last_s_ptr = s_ptr
                last_p_ptr = p_ptr
            elif last_p_ptr != -1:
                last_s_ptr += 1
                s_ptr = last_s_ptr
                p_ptr = last_p_ptr
            else:
                return False
            
        while p_ptr < len(p) and p[p_ptr] == '*':
            p_ptr += 1
        
        return p_ptr == len(p)
    
# dp with rolling window
# Time:  O(m * n)
# Space: O(m + n)
class Solution2:
    # @return a boolean
    def isMatch(self, s, p):
        k = 2
        result = [[False for j in xrange(len(p) + 1)] for i in xrange(k)]

        result[0][0] = True
        for i in xrange(1, len(p) + 1):
            if p[i-1] == '*':
                result[0][i] = result[0][i-1]
        for i in xrange(1,len(s) + 1):
            result[i % k][0] = False
            for j in xrange(1, len(p) + 1):
                if p[j-1] != '*':
                    result[i % k][j] = result[(i-1) % k][j-1] and (s[i-1] == p[j-1] or p[j-1] == '?')
                else:
                    result[i % k][j] = result[i % k][j-1] or result[(i-1) % k][j]
                    
        return result[len(s) % k][len(p)]

# dp
# Time:  O(m * n)
# Space: O(m * n)
class Solution3:
    # @return a boolean
    def isMatch(self, s, p):
        result = [[False for j in xrange(len(p) + 1)] for i in xrange(len(s) + 1)]

        result[0][0] = True
        for i in xrange(1, len(p) + 1):
            if p[i-1] == '*':
                result[0][i] = result[0][i-1]
        for i in xrange(1,len(s) + 1):
            result[i][0] = False
            for j in xrange(1, len(p) + 1):
                if p[j-1] != '*':
                    result[i][j] = result[i-1][j-1] and (s[i-1] == p[j-1] or p[j-1] == '?')
                else:
                    result[i][j] = result[i][j-1] or result[i-1][j]
                    
        return result[len(s)][len(p)]


# recursive, slowest
class Solution4:
    # @return a boolean
    def isMatch(self, s, p):
        if not p:
            return not s
        
        if p[0] != '*':
            if not s or (p[0] == s[0] or p[0] == '?'):
                return self.isMatch(s[1:], p[1:])
            else:
                return False
        else:
            while len(s) > 0:
                if self.isMatch(s, p[1:]):
                    return True
                s = s[1:]
            return self.isMatch(s, p[1:])

if __name__ == "__main__":
    print Solution().isMatch("aaaabaaaab","a*b*b")
    print Solution().isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c")
    print Solution().isMatch("aa","a")
    print Solution().isMatch("aa","aa")
    print Solution().isMatch("aaa","aa")
    print Solution().isMatch("aa", "a*")
    print Solution().isMatch("aa", "?*")
    print Solution().isMatch("ab", "?*")
    print Solution().isMatch("aab", "c*a*b")
