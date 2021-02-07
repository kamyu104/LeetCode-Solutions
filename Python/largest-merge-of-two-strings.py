# Time:  O(n * m)
# Space: O(n + m)

import collections


class Solution(object):
    def largestMerge(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        q1 = collections.deque(word1)
        q2 = collections.deque(word2)
        result = []
        while q1 or q2:
            if q1 > q2:
                result.append(q1.popleft())
            else:
                result.append(q2.popleft())
        return "".join(result)
