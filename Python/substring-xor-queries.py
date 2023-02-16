# Time:  O(n * logr + q), r = max(a^b for a, b in queries)
# Space: O(min(n * logr, r))

# hash table
class Solution(object):
    def substringXorQueries(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[List[int]]
        """
        mx = max(a^b for a, b in queries)
        lookup = {}
        for i in xrange(len(s)):
            curr = 0
            for j in xrange(i, len(s)):
                curr = (curr<<1)+int(s[j])
                if curr > mx:
                    break
                if curr not in lookup:
                    lookup[curr] = [i, j]
                if s[i] == '0':
                    break
        return [lookup[a^b] if a^b in lookup else [-1, -1] for a, b in queries]
