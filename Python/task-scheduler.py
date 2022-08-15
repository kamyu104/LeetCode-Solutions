# Time:  O(n)
# Space: O(26) = O(1)

from collections import Counter


class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        counter = Counter(tasks)
        _, max_count = counter.most_common(1)[0]
        return max((max_count-1) * (n+1) + counter.values().count(max_count), len(tasks))
