# Time:  O(n^2)
# Space: O(n)

import collections


class Solution(object):
    def maxCandies(self, status, candies, keys, containedBoxes, initialBoxes):
        """
        :type status: List[int]
        :type candies: List[int]
        :type keys: List[List[int]]
        :type containedBoxes: List[List[int]]
        :type initialBoxes: List[int]
        :rtype: int
        """
        result = 0
        q = collections.deque(initialBoxes)
        while q:
            changed = False
            for _ in xrange(len(q)):
                box = q.popleft()
                if not status[box]:
                    q.append(box)
                    continue
                changed = True
                result += candies[box]
                for contained_key in keys[box]:
                    status[contained_key] = 1
                for contained_box in containedBoxes[box]:
                    q.append(contained_box)
            if not changed:
                break
        return result
