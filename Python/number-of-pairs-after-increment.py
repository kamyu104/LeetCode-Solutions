# Time:  O(n + m + q * sqrt(m * n)), n = len(nums1), m = len(nums2)
# Space: O(n + m)

import collections


# freq table, sqrt decomposition
class Solution(object):
    def numberOfPairs(self, nums1, nums2, queries):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        def update(cnt, left, right, val):
            for i in xrange(left, right+1):
                cnt[nums2[i]] -= 1
                if not cnt[nums2[i]]:
                    del cnt[nums2[i]]
                nums2[i] += val
                cnt[nums2[i]] += 1
    
        cnt1 = collections.defaultdict(int)
        for x in nums1:
            cnt1[x] += 1
        B = int((len(cnt1)*len(nums2))**0.5)+1
        cnt2 = [collections.defaultdict(int) for _ in xrange(ceil_divide(len(nums2), B))]
        for i in xrange(len(cnt2)): 
            for j in xrange(i*B, min(i*B+B, len(nums2))):
                cnt2[i][nums2[j]] += 1
        lazy = [0]*len(cnt2)
        result = []
        for q in queries:
            if q[0] == 2:
                tot = q[1]
                result.append(sum(cnt2[i][(tot-x)-lazy[i]]*c for x, c in cnt1.iteritems() for i in xrange(len(cnt2)) if (tot-x)-lazy[i] in cnt2[i]))
                continue
            x, y, val = q[1], q[2], q[3]
            if x//B == y//B:
                update(cnt2[x//B], x, y, val)
                continue
            update(cnt2[x//B], x, ((x//B)+1)*B-1, val)
            for i in xrange((x//B)+1, y//B):
                lazy[i] += val
            update(cnt2[y//B], (y//B)*B, y, val)
        return result
