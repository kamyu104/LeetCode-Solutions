# Time:  O(n + tlogt)
# Space: O(n)

import collections


# freq table, sort, greedy
class Solution(object):
    def maxProfit(self, workers, tasks):
        """
        :type workers: List[int]
        :type tasks: List[List[int]]
        :rtype: int
        """
        cnt = collections.defaultdict(int)
        for x in workers:
            cnt[x] += 1
        tasks.sort(key=lambda x: x[1], reverse=True)
        result = 0
        k = 1
        for s, p in tasks:
            if cnt[s]:
                cnt[s] -= 1
                result += p
            elif k:
                k -= 1
                result += p
        return result
