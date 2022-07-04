# Time:  O(nlogn)
# Space: O(1)

import itertools


# greedy
class Solution(object):
    def minimumTime(self, jobs, workers):
        """
        :type jobs: List[int]
        :type workers: List[int]
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+(b-1))//b

        jobs.sort()
        workers.sort()
        return max(ceil_divide(j, w) for j, w in itertools.izip(jobs, workers))
