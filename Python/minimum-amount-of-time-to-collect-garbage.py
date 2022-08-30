# Time:  O(n * l), l = max(len(g) for g in garbage) = O(10)
# Space: O(1)

# simulation, prefix sum
class Solution(object):
    def garbageCollection(self, garbage, travel):
        """
        :type garbage: List[str]
        :type travel: List[int]
        :rtype: int
        """
        result = 0
        lookup = {}
        for i in xrange(len(garbage)):
            for c in garbage[i]:
                lookup[c] = i
            if i+1 < len(travel):
                travel[i+1] += travel[i]
            result += len(garbage[i])
        result += sum(travel[v-1] for _, v in lookup.iteritems() if v-1 >= 0)
        return result


# Time:  O(n * l), l = max(len(g) for g in garbage) = O(10)
# Space: O(1)
# simulation, prefix sum
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
