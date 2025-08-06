# Time:   O(n)
# Spacee: O(1)

# greedy
class Solution(object):
    def earliestFinishTime(self, landStartTime, landDuration, waterStartTime, waterDuration):
        """
        :type landStartTime: List[int]
        :type landDuration: List[int]
        :type waterStartTime: List[int]
        :type waterDuration: List[int]
        :rtype: int
        """
        mn_land = min(landStartTime[i]+landDuration[i] for i in xrange(len(landStartTime)))
        mn_water = min(waterStartTime[i]+waterDuration[i] for i in xrange(len(waterStartTime)))
        return min(min(max(landStartTime[i], mn_water)+landDuration[i] for i in xrange(len(landStartTime))), 
                   min(max(waterStartTime[i], mn_land)+waterDuration[i] for i in xrange(len(waterStartTime))))
