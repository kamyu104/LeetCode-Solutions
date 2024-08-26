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


# Time:  O(n * l^2)
# Space: O(n + l^2) = O(n)
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
            for x in at_most_1(x):
                if x not in cnt1:
                    continue
                cnt2[x] += v
        return result


# Time:  O(n * l^(2 * k))
# Space: O(n + l^(2 * k)) = O(n)
import collections


# freq table, combinatorics
class Solution3(object):
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
            result = {x}
            q = [x]
            while q:
                if k == 0:
                    break 
                new_q = []
                for x in q:
                    for i in xrange(L):
                        a = x//POW10[i]%10
                        for j in xrange(i+1, L):
                            b = x//POW10[j]%10
                            y = x-a*(POW10[i]-POW10[j])+b*(POW10[i]-POW10[j])
                            if y in result:
                                continue
                            result.add(y)
                            new_q.append(y)
                q = new_q
                k -= 1
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

