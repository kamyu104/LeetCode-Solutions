# Time:  O(nlogr)
# Space: O(1)

class Solution(object):
    def minmaxGasDist(self, stations, K):
        """
        :type stations: List[int]
        :type K: int
        :rtype: float
        """
        def possible(stations, K, guess):
            return sum(int((stations[i+1]-stations[i]) / guess)
                       for i in xrange(len(stations)-1)) <= K

        left, right = 0, 10**8
        while right-left > 1e-6:
            mid = left + (right-left)/2.0
            if possible(mid):
                right = mid
            else:
                left = mid
        return left

