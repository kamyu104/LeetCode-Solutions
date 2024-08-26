# Time:  O(n * l^2)
# Space: O(n)

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
        cnt2 = collections.Counter()
        for x, v in cnt1.iteritems():
            for i in xrange(L):
                a = x//POW10[i]%10
                for j in xrange(i+1, L):
                    b = x//POW10[j]%10
                    if a == b or x-a*(POW10[i]-POW10[j])+b*(POW10[i]-POW10[j]) not in cnt1:
                        continue
                    cnt2[x-a*(POW10[i]-POW10[j])+b*(POW10[i]-POW10[j])] += v
        return sum(v*(v-1)//2 for v in cnt1.itervalues())+sum(v*cnt2[x] for x, v in cnt1.iteritems())//2


# Time:  O(n * l^(2 * k)) = O(n * l^2)
# Space: O(n + l^(2 * k)) = O(n + l^2) = O(n)
import collections


# freq table, combinatorics, bfs
class Solution2(object):
    def countPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        L = 7
        K = 1
        POW10 = [0]*L
        POW10[0] = 1
        for i in xrange(L-1):
            POW10[i+1] = POW10[i]*10
        def at_most(k, x):
            lookup = {x}
            result = [x]
            u = 0
            for _ in xrange(k):
                for u in xrange(u, len(result)):
                    x = result[u]
                    for i in xrange(L):
                        a = x//POW10[i]%10
                        for j in xrange(i+1, L):
                            b = x//POW10[j]%10
                            if a == b:
                                continue
                            y = x-a*(POW10[i]-POW10[j])+b*(POW10[i]-POW10[j])
                            if y in lookup:
                                continue
                            lookup.add(y)
                            result.append(y)
            return result

        result = 0
        cnt1 = collections.Counter(nums)
        cnt2 = collections.Counter()
        for x, v in cnt1.iteritems():
            result += cnt2[x]*v+v*(v-1)//2
            for x in at_most(K, x):
                if x not in cnt1:
                    continue
                cnt2[x] += v
        return result

