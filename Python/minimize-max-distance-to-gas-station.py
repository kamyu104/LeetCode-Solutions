# Time:  O(nlogr)
# Space: O(1)

# On a horizontal number line, we have gas stations at positions
# stations[0], stations[1], ..., stations[N-1], where N = stations.length.
#
# Now, we add K more gas stations so that D,
# the maximum distance between adjacent gas stations, is minimized.
#
# Return the smallest possible value of D.
#
# Example:
#
# Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
# Output: 0.500000
#   
# Note:
# - stations.length will be an integer in range [10, 2000].
# - stations[i] will be an integer in range [0, 10^8].
# - K will be an integer in range [1, 10^6].
# - Answers within 10^-6 of the true value will be accepted as correct.

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
