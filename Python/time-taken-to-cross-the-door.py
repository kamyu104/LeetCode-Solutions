# Time:  O(n)
# Space: O(n)

import collections


# queue, simulation
class Solution(object):
    def timeTaken(self, arrival, state):
        """
        :type arrival: List[int]
        :type state: List[int]
        :rtype: List[int]
        """
        def go_until(t):
            while curr[0] <= t and any(q):
                if not q[direction[0]]:
                    direction[0] ^= 1
                result[q[direction[0]].popleft()] = curr[0]
                curr[0] += 1
    
        ENTERING, EXITING = range(2)
        result = [0]*len(arrival)
        curr, direction = [0], [EXITING]
        q = [collections.deque(), collections.deque()]
        for i, (a, s) in enumerate(itertools.izip(arrival, state)):
            go_until(a-1)
            q[s].append(i)
            if not (a <= curr[0]):
                curr, direction = [a], [EXITING]
        go_until(float("inf"))
        return result
