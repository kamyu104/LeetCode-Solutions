# Time:  O(n)
# Space: O(min(n, r)), r is the range size of nums

import collections


class Solution(object):
    def twoOutOfThree(self, nums1, nums2, nums3):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type nums3: List[int]
        :rtype: List[int]
        """
        K = 2
        cnt = collections.Counter()
        for nums in nums1, nums2, nums3:
            cnt.update(set(nums))
        return [x for x, c in cnt.iteritems() if c >= K]


# Time:  O(n)
# Space: O(min(n, r)), r is the range size of nums
import collections


class Solution2(object):
    def twoOutOfThree(self, nums1, nums2, nums3):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type nums3: List[int]
        :rtype: List[int]
        """
        K = 2
        cnt = collections.Counter()
        result = []
        for nums in nums1, nums2, nums3:
            for x in set(nums):
                cnt[x] += 1
                if cnt[x] == K:
                    result.append(x)
        return result
