# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def boyer_moore_majority_vote():
            result, cnt = None, 0
            for x in nums:
                if not cnt:
                    result = x
                if x == result:
                    cnt += 1
                else:
                    cnt -= 1
            return result

        return boyer_moore_majority_vote()


# Time:  O(n)
# Space: O(n)
import collections


class Solution2(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return collections.Counter(nums).most_common(1)[0][0]


# Time:  O(nlogn)
# Space: O(n)
import collections


class Solution3(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sorted(collections.Counter(nums).items(), key=lambda a: a[1], reverse=True)[0][0]
