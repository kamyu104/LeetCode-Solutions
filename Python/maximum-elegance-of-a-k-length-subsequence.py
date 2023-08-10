# Time:  O(nlogk)
# Space: O(n)

import collections
import heapq


# heap, greedy
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
        lookup2 = collections.defaultdict(int)
        for p, c in items:
            if c in lookup:
                continue
            lookup2[c] = max(lookup2[c], p)
        l = len(lookup)
        result = curr+l**2
        for p in heapq.nlargest(len(stk), lookup2.itervalues()):
            curr += p-stk.pop()
            l += 1
            result = max(result, curr+l**2) 
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
