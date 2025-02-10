# Time:  O(m + r * logn), m = len(groups), n = len(elements), r = max(groups)
# Space: O(r)

# hash table, number theory
class Solution(object):
    def assignElements(self, groups, elements):
        """
        :type groups: List[int]
        :type elements: List[int]
        :rtype: List[int]
        """
        mx = max(groups)
        lookup = [-1]*mx
        for i, x in enumerate(elements):
            if x > mx or lookup[x-1] != -1:
                continue
            for y in xrange(x, mx+1, x):
                if lookup[y-1] == -1:
                    lookup[y-1] = i
        return [lookup[x-1] for x in groups]   
