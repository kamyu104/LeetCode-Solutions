# Time:  O(n)
# Space: O(n)

import collections


# deque
class Solution(object):
    def finalString(self, s):
        """
        :type s: str
        :rtype: str
        """
        dq = collections.deque()
        parity = 0
        for x in s:
            if x == 'i':
                parity ^= 1
            else:
                dq.appendleft(x) if parity else dq.append(x)
        if parity:
            dq.reverse()
        return "".join(dq)
