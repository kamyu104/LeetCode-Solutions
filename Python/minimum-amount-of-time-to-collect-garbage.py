# Time:  O(n * l), l = max(g for g in garbage) = O(10)
# Space: O(1)

# simulation
class Solution(object):
    def garbageCollection(self, garbage, travel):
        """
        :type garbage: List[str]
        :type travel: List[int]
        :rtype: int
        """
        result = 0
        lookup = {}
        for i in reversed(xrange(len(garbage))):
            for c in garbage[i]:
                if c not in lookup:
                    lookup[c] = i
            result += len(garbage[i])
        lasts = sorted(lookup.itervalues(), reverse=True)
        curr = 0
        for i in xrange(len(garbage)):
            while lasts[-1] == i:
                result += curr
                lasts.pop()
                if not lasts:
                    break
            if i < len(travel):
                curr += travel[i]
        return result


# Time:  O(n * l), l = max(g for g in garbage) = O(10)
# Space: O(1)
# simulation
class Solution2(object):
    def garbageCollection(self, garbage, travel):
        """
        :type garbage: List[str]
        :type travel: List[int]
        :rtype: int
        """
        result = 0
        for t in 'MPG':
            curr = 0
            for i in xrange(len(garbage)):
                cnt = garbage[i].count(t) 
                if cnt:
                    result += curr+cnt
                    curr = 0
                if i < len(travel):
                    curr += travel[i]
        return result
