# Time:  O(n)
# Space: O(1)

import collections
import string


class Solution(object):
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        count = collections.defaultdict(int)
        for c in s:
            count[c] += 1
        for c in t:
            count[c] -= 1
            if count[c] < 0:
                return False
        return True


# Time:  O(nlogn)
# Space: O(n)
class Solution2(object):
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isAnagram(self, s, t):
        return sorted(s) == sorted(t)


# Time:  O(n)
# Space: O(n)
class Solution3(object):
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isAnagram(self, s, t):
        return collections.Counter(s) == collections.Counter(t)
