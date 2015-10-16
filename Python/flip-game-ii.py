# Time:  O(n^(c+2)), n is length of string, c is count of "++"
# Space: O(c * n), recursion would be called at most c in depth.
#                  Besides, it costs n space for modifying string at each depth.

class Solution(object):
    def canWin(self, s):
        """
        :type s: str
        :rtype: bool
        """
        i, n = 0, len(s) - 1
        is_win = False
        while not is_win and i < n:                                     # O(n) time
            if s[i] == '+':
                while not is_win and i < n and s[i+1] == '+':           # O(c) time
                     # t(n, c) = n * (t(n, c-1) + n) = ... = n^c * t(n, 0) + n^2 * (1 + n + ... + n^(c-1))
                     # = n^(c+1) + n^2 * (n^c - 1) / (n-1) = O(n^(c+2))
                    is_win = not self.canWin(s[:i] + '--' + s[i+2:])    # O(n) space
                    i += 1
            i += 1
        return is_win
