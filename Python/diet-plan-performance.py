# Time:  O(n)
# Space: O(1)

import itertools


class Solution(object):
    def dietPlanPerformance(self, calories, k, lower, upper):
        """
        :type calories: List[int]
        :type k: int
        :type lower: int
        :type upper: int
        :rtype: int
        """
        total = sum(itertools.islice(calories, 0, k))
        result = int(total > upper)-int(total < lower)
        for i in xrange(k, len(calories)):
            total += calories[i]-calories[i-k]
            result += int(total > upper)-int(total < lower)
        return result
