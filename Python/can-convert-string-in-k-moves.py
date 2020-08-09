# Time:  O(n)
# Space: O(1)

import itertools


class Solution(object):
    def canConvertString(self, s, t, k):
        """
        :type s: str
        :type t: str
        :type k: int
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        cnt = [0]*26
        for a, b in itertools.izip(s, t):
            diff = (ord(b)-ord(a)) % len(cnt)
            if diff != 0 and cnt[diff]*len(cnt) + diff > k:
                return False
            cnt[diff] += 1
        return True
