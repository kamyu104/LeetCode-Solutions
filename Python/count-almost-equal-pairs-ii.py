# Time:  O(n * l^4)
# Space: O(n * l^2 + min(n * l^4, n^2))

import collections


# freq table, combinatorics
class Solution(object):
    def countPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        L = 7
        POW10 = [0]*L
        POW10[0] = 1
        for i in xrange(L-1):
            POW10[i+1] = POW10[i]*10
        cnt1 = collections.Counter(nums)
        adj = collections.defaultdict(list)
        cnt = list(cnt1.iteritems())
        for idx in xrange(len(cnt)):
            adj[cnt[idx][0]].append(idx)
            for i in xrange(L):
                a = cnt[idx][0]//POW10[i]%10
                for j in xrange(i+1, L):
                    b = cnt[idx][0]//POW10[j]%10
                    if a == b:
                        continue
                    adj[cnt[idx][0]-a*(POW10[i]-POW10[j])+b*(POW10[i]-POW10[j])].append(idx)
        result = sum(v*(v-1)//2 for v in cnt1.itervalues())
        lookup = set()
        for x, neighbors in adj.iteritems():
            for i in xrange(len(neighbors)):
                v1 = cnt[neighbors[i]][1]
                for j in xrange(i+1, len(neighbors)):
                    v2 = cnt[neighbors[j]][1]
                    if (neighbors[i], neighbors[j]) in lookup:
                        continue
                    lookup.add((neighbors[i], neighbors[j]))
                    result += v1*v2
        return result


# Time:  O(n * l^4)
# Space: O(n + l^4)
import collections


# freq table, combinatorics
class Solution2(object):
    def countPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        L = 7
        POW10 = [0]*L
        POW10[0] = 1
        for i in xrange(L-1):
            POW10[i+1] = POW10[i]*10
        def at_most_1(x):
            result = {x}
            for i in xrange(L):
                a = x//POW10[i]%10
                for j in xrange(i+1, L):
                    b = x//POW10[j]%10
                    if a == b:
                        continue
                    result.add(x-a*(POW10[i]-POW10[j])+b*(POW10[i]-POW10[j]))
            return result

        result = 0
        cnt1 = collections.Counter(nums)
        cnt2 = collections.Counter()
        for x, v in cnt1.iteritems():
            result += cnt2[x]*v+v*(v-1)//2
            for x in {x2 for x1 in at_most_1(x) for x2 in at_most_1(x1)}:
                if x not in cnt1:
                    continue
                cnt2[x] += v
        return result
