# Time:  O(n * b), n is the length of gene string, b is size of bank
# Space: O(b)

from collections import deque

class Solution(object):
    def minMutation(self, start, end, bank):
        """
        :type start: str
        :type end: str
        :type bank: List[str]
        :rtype: int
        """
        lookup = {}
        for b in bank:
            lookup[b] = False

        q = deque([(start, 0)])
        while q:
            cur, level = q.popleft()
            if cur == end:
                return level

            for i in xrange(len(cur)):
                for c in ['A', 'T', 'C', 'G']:
                    if cur[i] == c:
                        continue

                    next_str = cur[:i] + c + cur[i+1:]
                    if next_str in lookup and lookup[next_str] == False:
                        q.append((next_str, level+1))
                        lookup[next_str] = True

        return -1

