# Time:  O(n)
# Space: O(n)

import heapq
import collections


# partial sort, freq table
class Solution(object):
    def minimumAddedInteger(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        def check(cnt2, cnt1):
            # return cnt2 <= cnt1  # for python3
            return all(cnt1.get(k, 0)-v >= 0 for k, v in cnt2.iteritems())  # for python2
            
        mx = max(nums2)
        cnt2 = collections.Counter(nums2)
        return next(d for d in [mx-x for x in heapq.nlargest(3, nums1)] if check(cnt2, collections.Counter(x+d for x in nums1)))


# Time:  O(n)
# Space: O(n)
import collections


# partial sort, freq table
class Solution2(object):
    def minimumAddedInteger(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        def check(cnt2, cnt1):
            # return cnt2 <= cnt1  # for python3
            return all(cnt1.get(k, 0)-v >= 0 for k, v in cnt2.iteritems())  # for python2
        
        def topk(a, k):  # Time: O(k * n)
            result = [float("-inf")]*k
            for x in a:
                for i in xrange(len(result)):
                    if x > result[i]:
                        result[i], x = x, result[i]
            return result
    
        mx = max(nums2)
        cnt2 = collections.Counter(nums2)
        return next(d for d in [mx-x for x in topk(nums1, 3)] if check(cnt2, collections.Counter(x+d for x in nums1)))


# Time:  O(nlogn)
# Space: O(1)
# sort
class Solution3(object):
    def minimumAddedInteger(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        nums1.sort()
        nums2.sort()
        for i in xrange(3):
            d = nums2[-1]-nums1[~i]
            cnt = 0
            for j in xrange(len(nums2)):
                while j+cnt < len(nums1) and nums1[j+cnt]+d != nums2[j]:
                    cnt += 1
            if cnt <= 2:
                return d
        return -1
