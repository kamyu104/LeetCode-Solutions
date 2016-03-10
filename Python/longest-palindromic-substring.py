# Time:  O(n)
# Space: O(n)
#
# Given a string S, find the longest palindromic substring in S.
# You may assume that the maximum length of S is 1000,
#  and there exists one unique longest palindromic substring.
#

# Manacher's Algorithm
# http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        def preProcess(s):
            if not s:
                return "^$"
            T = "^"
            for i in s:
                T +=  "#" + i
            T += "#$"
            return T

        T = preProcess(s)
        P = [0] * len(T) 
        center, right = 0, 0
        for i in xrange(1, len(T) - 1):
            i_mirror = 2 * center - i
            if right > i:
                P[i] = min(right - i, P[i_mirror])
            else:
                P[i] = 0

            while T[i + 1 + P[i]] == T[i - 1 - P[i]]:
                P[i] += 1

            if i + P[i] > right:
                center, right = i, i + P[i]       
        
        max_i = 0
        for i in xrange(1, len(T) - 1):
            if P[i] > P[max_i]:
                max_i = i
        start = (max_i - 1 - P[max_i]) / 2
        return s[start : start + P[max_i]]

    
if __name__ == "__main__":
    print Solution().longestPalindrome("abb")
