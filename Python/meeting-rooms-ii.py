# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    # @param {Interval[]} intervals
    # @return {integer}
    def minMeetingRooms(self, intervals):
        result, curr = 0, 0
        line = [x for i, j in intervals for x in [[i, 1], [j, -1]]]
        line.sort()
        for _, num in line:
            curr += num
            result = max(result, curr)
        return result


# Time:  O(nlogn)
# Space: O(n)
class Solution2(object):
    # @param {Interval[]} intervals
    # @return {integer}
    def minMeetingRooms(self, intervals):
        starts, ends = [], []
        for start, end in intervals:
            starts.append(start)
            ends.append(end)

        starts.sort()
        ends.sort()

        s, e = 0, 0
        min_rooms, cnt_rooms = 0, 0
        while s < len(starts):
            if starts[s] < ends[e]:
                cnt_rooms += 1  # Acquire a room.
                # Update the min number of rooms.
                min_rooms = max(min_rooms, cnt_rooms)
                s += 1
            else:
                cnt_rooms -= 1  # Release a room.
                e += 1

        return min_rooms


# Time: O(nlogn)
# Space: O(n)
from heapq import heappush, heappop


class Solution3(object):
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        if not intervals:
            return 0
        
        intervals.sort(key=lambda x: x[0])
        free_rooms = []
        
        heappush(free_rooms, intervals[0][1])
        for interval in intervals[1:]:
            if free_rooms[0] <= interval[0]:
                heappop(free_rooms)
            
            heappush(free_rooms, interval[1])
        
        return len(free_rooms)
