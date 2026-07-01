# Time:  O(nlogn)
# Space: O(n)

# sort
class Solution(object):
    def filterOccupiedIntervals(self, occupiedIntervals, freeStart, freeEnd):
        """
        :type occupiedIntervals: List[List[int]]
        :type freeStart: int
        :type freeEnd: int
        :rtype: List[List[int]]
        """
        def merged_intervals(intervals):
            intervals.sort(key=lambda x: x[0])
            merged = []
            for l, r in intervals:
                if not merged or merged[-1][1]+1 < l:
                     merged.append([l, r])
                else:
                    merged[-1][1] = max(merged[-1][1], r)                   
            return merged
        
        def overlapped(a, b):
            return max(a[0], b[0]) <= min(a[1], b[1])
        
        result = []
        for l, r in merged_intervals(occupiedIntervals):
            if not overlapped([l, r], [freeStart, freeEnd]):
                result.append([l, r])
                continue
            if l <= freeStart-1:
                result.append([l, freeStart-1])
            if freeEnd+1 <= r:
                result.append([freeEnd+1, r])
        return result
