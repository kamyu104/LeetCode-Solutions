# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def predictPartyVictory(self, senate):
        """
        :type senate: str
        :rtype: str
        """
        n = len(senate)
        radiant, dire = collections.deque(), collections.deque()
        for i, c in enumerate(senate):
            if c == 'R':
                radiant.append(i)
            else:
                dire.append(i)
        while radiant and dire:
            r_idx, d_idx = radiant.popleft(), dire.popleft()
            if r_idx < d_idx:
                radiant.append(r_idx+n)
            else:
                dire.append(d_idx+n)
        return "Radiant" if len(radiant) > len(dire) else "Dire"

