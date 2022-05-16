# Time:  O(a^2 * n), a is the size of alphabets
# Space: O(a)

import itertools


# kadane's algorithm
class Solution(object):
    def largestVariance(self, s):
        """
        :type s: str
        :rtype: int
        """
        def modified_kadane(a, x, y):
            result = curr = 0
            lookup = [0]*2
            remain = [a.count(x), a.count(y)]
            for c in a:
                if c not in (x, y):
                    continue
                lookup[c != x] = 1
                remain[c != x] -= 1
                curr += 1 if c == x else -1
                if curr < 0 and remain[0] and remain[1]:
                    curr = lookup[0] = lookup[1] = 0  # reset states if the remain has both x, y
                if lookup[0] and lookup[1]:
                    result = max(result, curr)  # update result if x, y both exist
            return result

        alphabets = set(s)
        return max(modified_kadane(s, x, y) for x, y in itertools.permutations(alphabets, 2)) if len(alphabets) >= 2 else 0
