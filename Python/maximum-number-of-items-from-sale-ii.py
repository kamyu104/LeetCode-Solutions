# Time:  O(rlogr + nlogn) = O(nlogn), r = max(f for f, _ in items) <= n
# Space: O(r + n) = O(n)

import collections


# freq table, sort, greedy
class Solution(object):
    def maximumSaleItems(self, items, budget):
        """
        :type items: List[List[int]]
        :type budget: int
        :rtype: int
        """
        NEG_INF = float("-inf")
        cnt = [0]*(max(f for f, _ in items)+1)
        for f, _ in items:
            cnt[f] += 1
        total = [0]*len(cnt)
        for i in xrange(1, len(total)):
            if not cnt[i]:
                continue
            for j in xrange(i, len(total), i):
                total[i] += cnt[j]
        min_p = min(p for _, p in items)
        group = collections.defaultdict(int)
        for f, price in items:
            if price >= 2*min_p:
                continue
            group[price] += total[f]-1
        result = 0
        for p in sorted(group):
            c = min(group[p], budget//p)
            result += 2*c
            budget -= c*p
            if not budget:
                break
        result += budget//min_p
        return result
