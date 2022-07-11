# Time:  O(nlogn + mlogm)
# Space: O(1)

# sort, two pointers
class Solution(object):
    def latestTimeCatchTheBus(self, buses, passengers, capacity):
        """
        :type buses: List[int]
        :type passengers: List[int]
        :type capacity: int
        :rtype: int
        """
        buses.sort()
        passengers.sort()
        cnt = j = 0
        for i in xrange(len(buses)-1):
            while j < len(passengers) and passengers[j] <= buses[i]:
                cnt += 1
                j += 1
            cnt = max(cnt-capacity, 0)
        j -= max(cnt-capacity, 0)
        cnt = min(cnt, capacity)
        while j < len(passengers) and passengers[j] <= buses[-1] and cnt+1 <= capacity:
            cnt += 1
            j += 1
        return buses[-1] if cnt < capacity and (j-1 < 0 or passengers[j-1] != buses[-1]) else next(passengers[i]-1 for i in reversed(xrange(j)) if i-1 < 0 or passengers[i]-1 != passengers[i-1])
