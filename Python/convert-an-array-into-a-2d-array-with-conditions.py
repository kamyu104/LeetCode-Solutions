# Time:  O(n)
# Space: O(n)

import collections


# freq table, constructive algorithms
class Solution(object):
    def findMatrix(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        cnt = collections.Counter()
        for x in nums:
            if cnt[x] == len(result):
                result.append([])
            result[cnt[x]].append(x)
            cnt[x] += 1
        return result


# Time:  O(n)
# Space: O(n)
import collections


# freq table, constructive algorithms
class Solution2(object):
    def findMatrix(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        cnt = collections.Counter(nums)
        while cnt:
            result.append(cnt.keys())
            cnt = {k:v-1 for k, v in cnt.iteritems() if v-1}
        return result
