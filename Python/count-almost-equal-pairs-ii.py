# Time:  O(n * l^4)
# Space: O(n * l^2 + min(n * l^4, n^2)) = O(n * l^4)

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
        for u in adj.iterkeys():
            for i in xrange(len(adj[u])):
                v1 = cnt[adj[u][i]][1]
                for j in xrange(i+1, len(adj[u])):
                    v2 = cnt[adj[u][j]][1]
                    if (adj[u][i], adj[u][j]) in lookup:
                        continue
                    lookup.add((adj[u][i], adj[u][j]))
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
        def at_most_2(x):
            result = {x}
            for i in xrange(L):
                a = x//POW10[i]%10
                for j in xrange(i+1, L):
                    b = x//POW10[j]%10
                    if a == b:
                        continue
                    x += -a*(POW10[i]-POW10[j])+b*(POW10[i]-POW10[j])
                    result.add(x)
                    for k in xrange(L):
                        c = x//POW10[k]%10
                        for l in xrange(k+1, L):
                            d = x//POW10[l]%10
                            if c == d:
                                continue
                            result.add(x-c*(POW10[k]-POW10[l])+d*(POW10[k]-POW10[l]))
                    x -= -a*(POW10[i]-POW10[j])+b*(POW10[i]-POW10[j])
            return result

        result = 0
        cnt1 = collections.Counter(nums)
        cnt2 = collections.Counter()
        for x, v in cnt1.iteritems():
            result += cnt2[x]*v+v*(v-1)//2
            for x in at_most_2(x):
                if x not in cnt1:
                    continue
                cnt2[x] += v
        return result
