# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def canReach(self, arr, start):
        """
        :type arr: List[int]
        :type start: int
        :rtype: bool
        """
        q, lookup = collections.deque([start]), set([start])
        while q:
            i = q.popleft()
            if not arr[i]:
                return True
            for j in [i-arr[i], i+arr[i]]:
                if 0 <= j < len(arr) and j not in lookup:
                    lookup.add(j)
                    q.append(j) 
        return False
