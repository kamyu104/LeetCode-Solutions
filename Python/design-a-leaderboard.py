# Time:  ctor:  O(1)
#        add:   O(1)
#        top:   O(n)
#        reset: O(1)
# Space: O(n)

import collections
import random


class Leaderboard(object):

    def __init__(self):
        self.__lookup = collections.Counter()
        
    def addScore(self, playerId, score):
        """
        :type playerId: int
        :type score: int
        :rtype: None
        """
        self.__lookup[playerId] += score

    def top(self, K):
        """
        :type K: int
        :rtype: int
        """
        def kthElement(nums, k, compare):
            def PartitionAroundPivot(left, right, pivot_idx, nums, compare):
                new_pivot_idx = left
                nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]
                for i in xrange(left, right):
                    if compare(nums[i], nums[right]):
                        nums[i], nums[new_pivot_idx] = nums[new_pivot_idx], nums[i]
                        new_pivot_idx += 1

                nums[right], nums[new_pivot_idx] = nums[new_pivot_idx], nums[right]
                return new_pivot_idx

            left, right = 0, len(nums) - 1
            while left <= right:
                pivot_idx = random.randint(left, right)
                new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, nums, compare)
                if new_pivot_idx == k:
                    return
                elif new_pivot_idx > k:
                    right = new_pivot_idx - 1
                else:  # new_pivot_idx < k.
                    left = new_pivot_idx + 1
        
        scores = self.__lookup.values()
        kthElement(scores, K, lambda a, b: a > b)
        return sum(scores[:K])

    def reset(self, playerId):
        """
        :type playerId: int
        :rtype: None
        """
        self.__lookup[playerId] = 0
