# Time:  O(n)
# Space: O(1)

import collections
import string


class Solution(object):
    def checkIfCanBreak(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        def is_break(count1, count2):
            curr1, curr2 = 0, 0
            for c in string.ascii_lowercase:
                curr1 += count1[c]
                curr2 += count2[c]
                if curr1 < curr2:
                    return False
            return True

        count1, count2 = collections.Counter(s1), collections.Counter(s2)
        return is_break(count1, count2) or is_break(count2, count1)
    

# Time:  O(nlogn)
# Space: O(1)
import itertools


class Solution2(object):
    def checkIfCanBreak(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        return not {1, -1}.issubset(set(cmp(a, b) for a, b in itertools.izip(sorted(s1), sorted(s2))))


# Time:  O(nlogn)
# Space: O(1)
import itertools


class Solution3(object):
    def checkIfCanBreak(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        s1, s2 = sorted(s1), sorted(s2)
        return all(a >= b for a, b in itertools.izip(s1, s2)) or \
               all(a <= b for a, b in itertools.izip(s1, s2))
