# Time:  O(q)
# Space: O(q)

import collections


# freq table
class Solution(object):
    def queryResults(self, limit, queries):
        """
        :type limit: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        result = [0]*len(queries)
        lookup = {}
        cnt = collections.Counter()
        for i, (x, y) in enumerate(queries):
            if x in lookup:
                cnt[lookup[x]] -= 1
                if not cnt[lookup[x]]:
                    del cnt[lookup[x]]
            lookup[x] = y
            cnt[lookup[x]] += 1
            result[i] = len(cnt)
        return result
