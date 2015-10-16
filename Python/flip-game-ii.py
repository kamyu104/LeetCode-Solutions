# Time:  O(n + c^3 * 2^c * logc)
# Space: O(c * 2^c)

# hash solution.
# We have total O(2^c) game strings,
# and each hash key in hash table would cost O(c),
# each one has O(c) choices to the next one,
# and each one would cost O(clogc) to sort,
# so we get O((c * 2^c) * (c * clogc)) = O(c^3 * 2^c * logc) time.
# To cache the results of all combinations, thus O(c * 2^c) space.
class Solution(object):
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
class Solution2(object):
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
