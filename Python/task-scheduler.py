# Time:  O(n)
# Space: O(26) = O(1)

import collections

class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        count = collections.defaultdict(int)
        max_count = 0
        for task in tasks:
            count[task] += 1
            max_count = max(max_count, count[task])

        result = (max_count-1) * (n+1)
        for count in count.values():
            if count == max_count:
                result += 1
        return max(result, len(tasks))

