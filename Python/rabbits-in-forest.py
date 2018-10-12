# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def numRabbits(self, answers):
        """
        :type answers: List[int]
        :rtype: int
        """
        count = collections.Counter(answers)
        return sum((((k+1)+v-1)//(k+1))*(k+1) for k, v in count.iteritems())

