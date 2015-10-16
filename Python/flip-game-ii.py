# Time:  O(n^2)
# Space: O(n)

# The best theory solution (DP, O(n^2)) could be seen here:
# https://leetcode.com/discuss/64344/theory-matters-from-backtracking-128ms-to-dp-0m
class Solution(object):
    def canWin(self, s):
        g, g_final = [0], 0
        for p in itertools.imap(len, re.split('-+', s)):
            while len(g) <= p:
                # Theorem 2: g[game] = g[subgame1]^g[subgame2]^g[subgame3]...;
                # and find first missing number.
                g += min(set(xrange(p)) - {x^y for x, y in itertools.izip(g[:len(g)/2], g[-2:-len(g)/2-2:-1])}),
            g_final ^= g[p]
        return g_final > 0  # Theorem 1: First player must win iff g(current_state) != 0


# Time:  O(n + c^3 * 2^c * logc), n is length of string, c is count of "++"
# Space: O(c * 2^c)
# hash solution.
# We have total O(2^c) game strings,
# and each hash key in hash table would cost O(c),
# each one has O(c) choices to the next one,
# and each one would cost O(clogc) to sort,
# so we get O((c * 2^c) * (c * clogc)) = O(c^3 * 2^c * logc) time.
# To cache the results of all combinations, thus O(c * 2^c) space.
class Solution2(object):
    def canWin(self, s):
        """
        :type s: str
        :rtype: bool
        """
        lookup = {}

        def canWinHelper(consecutives):                                         # O(2^c) time
            consecutives = tuple(sorted(c for c in consecutives if c >= 2))     # O(clogc) time
            if consecutives not in lookup:
                lookup[consecutives] = any(not canWinHelper(consecutives[:i] + (j, c-2-j) + consecutives[i+1:])  # O(c) time
                                           for i, c in enumerate(consecutives)  # O(c) time
                                           for j in xrange(c - 1))              # O(c) time
            return lookup[consecutives]                                         # O(c) time

        # re.findall: O(n) time, canWinHelper: O(c) in depth
        return canWinHelper(map(len, re.findall(r'\+\++', s)))


# Time:  O(c * n * c!), n is length of string, c is count of "++"
# Space: O(c * n), recursion would be called at most c in depth.
#                  Besides, it costs n space for modifying string at each depth.
class Solution3(object):
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
                     # t(n, c) = c * (t(n, c-1) + n) + n = ...
                     # = c! * t(n, 0) + n * c! * (c + 1) * (1/0! + 1/1! + ... 1/c!)
                     # = n * c! + n * c! * (c + 1) * O(e) = O(c * n * c!)
                    is_win = not self.canWin(s[:i] + '--' + s[i+2:])    # O(n) space
                    i += 1
            i += 1
        return is_win
