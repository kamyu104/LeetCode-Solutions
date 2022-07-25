# Time:  O(nlogn)
# Space: O(1)

# math, sort
class Solution(object):
    def visibleMountains(self, peaks):
        """
        :type peaks: List[List[int]]
        :rtype: int
        """
        peaks.sort(key=lambda x: (x[0]-x[1], -(x[0]+x[1])))
        result = mx = 0
        for i in xrange(len(peaks)):
            if peaks[i][0]+peaks[i][1] <= mx:
                continue
            mx = peaks[i][0]+peaks[i][1]
            if i+1 == len(peaks) or peaks[i+1] != peaks[i]:
                result += 1
        return result
            
