# Time:  O(n)
# Space: O(1)

import itertools


# greedy, kadane's algorithm
class Solution(object):
    def maximumCostSubstring(self, s, chars, vals):
        """
        :type s: str
        :type chars: str
        :type vals: List[int]
        :rtype: int
        """
        def kadane(s):
            result = curr = 0
            for c in s:
                curr = max(curr+(lookup[c] if c in lookup else ord(c)-ord('a')+1), 0)
                result = max(result, curr)
            return result

        lookup = {}
        for c, v in itertools.izip(chars, vals):
            lookup[c] = v
        return kadane(s)
