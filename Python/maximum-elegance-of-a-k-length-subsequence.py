# Time:  O(nlogk)
# Space: O(n)

import collections
from sortedcontainers import SortedList


# heap, sorted list, greedy
class Solution(object):
    def findMaximumElegance(self, items, k):
        """
        :type items: List[List[int]]
        :type k: int
        :rtype: int
        """
        curr = 0
        lookup = set()
        stk = []
        for p, c in heapq.nlargest(k, items):
            if c in lookup:
                stk.append(p)
            curr += p
            lookup.add(c)
        sl = SortedList()
        lookup2 = {}
        for p, c in items:
            if c in lookup:
                continue;
            if c in lookup2:
                if lookup2[c] >= p:
                    continue;
                sl.remove((lookup2[c], c))
            lookup2[c] = p;
            sl.add((lookup2[c], c))
            if len(sl) > len(stk):
                del lookup2[sl[0][1]]
                del sl[0]
        result = curr+len(lookup)**2
        for p, c in reversed(sl):
            curr += p-stk.pop()
            lookup.add(c)
            result = max(result, curr+len(lookup)**2) 
        return result


# Time:  O(nlogn)
# Space: O(k)
# sort, greedy
class Solution2(object):
    def findMaximumElegance(self, items, k):
        """
        :type items: List[List[int]]
        :type k: int
        :rtype: int
        """
        items.sort(reverse=True)
        result = curr = 0
        lookup = set()
        stk = []
        for i, (p, c) in enumerate(items):
            if i < k:
                if c in lookup:
                    stk.append(p)
                curr += p
            elif c not in lookup:
                if not stk:
                    break
                curr += p-stk.pop()
            lookup.add(c)
            result = max(result, curr+len(lookup)**2)
        return result
