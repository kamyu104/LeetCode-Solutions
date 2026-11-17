# Time:  O(n + m)
# Space: O(n + m)

import collections


# freq table, z-function, prefix sum, sliding window
# Template: https://cp-algorithms.com/string/z-function.html
def z_function(s):  # Time: O(n), Space: O(n)
    z = [0]*len(s)
    l, r = 0, 0
    for i in xrange(1, len(z)):
        if i <= r:
            z[i] = min(r-i+1, z[i-l])
        while i+z[i] < len(z) and s[z[i]] == s[i+z[i]]:
            z[i] += 1
        if i+z[i]-1 > r:
            l, r = i, i+z[i]-1
    return z


class Solution(object):
    def countSuffix(self, nums, target):
        """
        :type nums: List[int]
        :type target: List[int]
        :rtype: List[int]
        """
        def update(x, d):
            cnt[x] += d
            if cnt[x] == 0:
                del cnt[x]

        z = z_function(nums+[0]+target)
        prefix = [0]*len(target)
        for i in xrange(len(target)-1):
            prefix[i+1] = prefix[i] if target[i] >= target[i+1] else i+1
        cnt = collections.defaultdict(int)
        for x in nums:
            cnt[x] += 1
        result = []
        for i in xrange(len(target)):
            update(target[i], -1)
            if i-len(nums)+1 < 0:
                continue
            result.append(max(min(z[len(nums)+1+(i-len(nums)+1)], len(nums)-1)-max(prefix[i]-(i-len(nums)+1), 0)+1, 0) if not cnt else 0)
            update(target[i-len(nums)+1], +1)
        return result
