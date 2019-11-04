# Time:  O(s * t)
# Space: O(s)

class Solution(object):
    def minWindow(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        lookup = [[None for _ in xrange(26)] for _ in xrange(len(S)+1)]
        find_char_next_pos = [None]*26
        for i in reversed(xrange(len(S))):
            find_char_next_pos[ord(S[i])-ord('a')] = i+1
            lookup[i] = list(find_char_next_pos)

        min_i, min_len = None, float("inf")
        for i in xrange(len(S)):
            if S[i] != T[0]:
                continue
            start = i
            for c in T:
                start = lookup[start][ord(c)-ord('a')]
                if start == None:
                    break
            else:
                if start-i < min_len:
                    min_i, min_len = i, start-i
        return S[min_i:min_i+min_len] if min_i is not None else ""

    
# Time:  O(s * t)
# Space: O(s)
class Solution2(object):
    def minWindow(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        dp = [[None for _ in xrange(len(S))] for _ in xrange(2)]
        for j, c in enumerate(S):
            if c == T[0]:
                dp[0][j] = j

        for i in xrange(1, len(T)):
            prev = None
            dp[i%2] = [None] * len(S)
            for j, c in enumerate(S):
                if prev is not None and c == T[i]:
                    dp[i%2][j] = prev
                if dp[(i-1)%2][j] is not None:
                    prev = dp[(i-1)%2][j]

        start, end = 0, len(S)
        for j, i in enumerate(dp[(len(T)-1)%2]):
            if i >= 0 and j-i < end-start:
                start, end = i, j
        return S[start:end+1] if end < len(S) else ""

