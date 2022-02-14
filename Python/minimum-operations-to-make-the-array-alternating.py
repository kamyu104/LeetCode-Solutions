# Time:  O(n)
# Space: O(n)

import collections


# freq table
class Solution(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def find_top1_and_top2(cnt):
            top1 = top2 = -1
            for k, v in cnt.iteritems():
                if top1 == -1 or v >= cnt[top1]:
                    top1, top2 = k, top1
                elif top2 == -1 or v > cnt[top2]:
                    top2 = k
            return top1, top2

        even = collections.Counter(nums[i] for i in xrange(0, len(nums), 2))
        odd = collections.Counter(nums[i] for i in xrange(1, len(nums), 2))
        even_top = find_top1_and_top2(even)
        odd_top = find_top1_and_top2(odd)
        if even_top[0] != odd_top[0]:
            return len(nums)-even[even_top[0]]-(odd[odd_top[0]] if odd_top[0] != -1 else 0)
        return min(len(nums)-even[even_top[0]]-(odd[odd_top[1]] if odd_top[1] != -1 else 0),
                   len(nums)-odd[odd_top[0]]-(even[even_top[1]] if even_top[1] != -1 else 0))

# Time:  O(n)
# Space: O(n)
import collections


# freq table
class Solution2(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        even = collections.Counter(nums[i] for i in xrange(0, len(nums), 2))
        odd = collections.Counter(nums[i] for i in xrange(1, len(nums), 2))
        even_top = even.most_common(2)  # Time: O(nlogk)
        odd_top = odd.most_common(2)  # Time: O(nlogk)
        if not odd_top or even_top[0][0] != odd_top[0][0]:
            return len(nums)-even_top[0][1]-(odd_top[0][1] if odd_top else 0)
        return min(len(nums)-even_top[0][1]-(odd_top[1][1] if len(odd_top) == 2 else 0),
                   len(nums)-odd_top[0][1]-(even_top[1][1] if len(even_top) == 2 else 0))
