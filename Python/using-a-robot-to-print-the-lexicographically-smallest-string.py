# Time:  O(n)
# Space: O(n)

import collections


# freq table, greedy
class Solution(object):
    def robotWithString(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = collections.Counter(s)
        result, stk = [], []
        mn = 'a'
        for c in s:
            stk.append(c)
            cnt[c] -= 1
            while mn < 'z' and cnt[mn] == 0:
                mn = chr(ord(mn)+1)
            while stk and stk[-1] <= mn:
                result.append(stk.pop())
        return "".join(result) 
