# Time:  O(26 * n * l)
# Space: O(n * l)

# hash table, math
class Solution(object):
    def distinctNames(self, ideas):
        """
        :type ideas: List[str]
        :rtype: int
        """
        lookup = [set() for _ in xrange(26)]
        for x in ideas:
            lookup[ord(x[0])-ord('a')].add(x[1:])
        result = 0
        for i in xrange(len(lookup)):
            for j in xrange(i+1, len(lookup)):
                common = len(lookup[i]&lookup[j])
                result += (len(lookup[i])-common)*(len(lookup[j])-common)
        return result*2
