# Time:  O(n)
# Space: O(n)

import collections


# freq table, prefix sum
class Solution(object):
    def countStableSubarrays(self, capacity):
        """
        :type capacity: List[int]
        :rtype: int
        """
        L = 3
        cnt = collections.defaultdict(lambda: collections.defaultdict(int))
        result = prefix = prefix2 = 0
        for i in xrange(len(capacity)):
            result += cnt[capacity[i]][prefix-capacity[i]]
            prefix += capacity[i]
            if (i+1)-L+1 >= 0:
                prefix2 += capacity[(i+1)-L+1]
                cnt[capacity[(i+1)-L+1]][prefix2] += 1
        return result


# Time:  O(n)
# Space: O(n)
import collections


# freq table, prefix sum
class Solution2(object):
    def countStableSubarrays(self, capacity):
        """
        :type capacity: List[int]
        :rtype: int
        """
        cnt = collections.defaultdict(lambda: collections.defaultdict(int))
        result = prefix = 0
        for i, x in enumerate(capacity):
            result += cnt[x][prefix-x]
            prefix += x
            cnt[x][prefix] += 1
            if x == 0 and i-1 >= 0 and capacity[i-1] == 0:
                result -= 1
        return result
