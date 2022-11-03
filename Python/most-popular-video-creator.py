# Time:  O(n)
# Space: O(n)

import collections
import itertools


# hash table
class Solution(object):
    def mostPopularCreator(self, creators, ids, views):
        """
        :type creators: List[str]
        :type ids: List[str]
        :type views: List[int]
        :rtype: List[List[str]]
        """
        cnt = collections.Counter()
        lookup = collections.defaultdict(lambda: (float("inf"), float("inf")))
        for c, i, v in itertools.izip(creators, ids, views):
            cnt[c] += v
            lookup[c] = min(lookup[c], (-v, i))
        mx = max(cnt.itervalues())
        return [[k, lookup[k][1]] for k, v in cnt.iteritems() if v == mx]
