# Time:  O(n^2)
# Space: O(n^2)

# Given a string S, find the number of different non-empty palindromic subsequences in S,
# and return that number modulo 10^9 + 7.
#
# A subsequence of a string S is obtained by deleting 0 or more characters from S.
#
# A sequence is palindromic if it is equal to the sequence reversed.
#
# Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is some i for which A_i != B_i.
#
# Example 1:
# Input: 
# S = 'bccb'
# Output: 6
# Explanation: 
# The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
# Note that 'bcb' is counted only once, even though it occurs twice.
#
# Example 2:
# Input: 
# S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
# Output: 104860361
#   
# Explanation: 
# There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.
# Note:
# - The length of S will be in the range [1, 1000].
# - Each character S[i] will be in the set {'a', 'b', 'c', 'd'}.

class Solution(object):
    def countPalindromicSubsequences(self, S):
        """
        :type S: str
        :rtype: int
        """
        def dp(i, j, prv, nxt, lookup):
            if lookup[i][j] is not None:
                return lookup[i][j]
            result = 1
            if i <= j:
                for x in xrange(4):
                    i0 = nxt[i][x]
                    j0 = prv[j][x]
                    if i <= i0 <= j:
                        result = (result + 1) % P
                    if None < i0 < j0:
                        result = (result + dp(i0+1, j0-1, prv, nxt, lookup)) % P
            result %= P
            lookup[i][j] = result
            return result
        
        prv = [None] * len(S)
        nxt = [None] * len(S)
    
        last = [None] * 4
        for i in xrange(len(S)):
            last[ord(S[i])-ord('a')] = i
            prv[i] = tuple(last)
            
        last = [None] * 4
        for i in reversed(xrange(len(S))):
            last[ord(S[i])-ord('a')] = i
            nxt[i] = tuple(last)
        
        P = 10**9 + 7
        lookup = [[None] * len(S) for _ in xrange(len(S))]        
        return dp(0, len(S)-1, prv, nxt, lookup) - 1
