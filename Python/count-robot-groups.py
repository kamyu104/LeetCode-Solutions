# Time:  O(n)
# Space: O(1)

# backward simulation, greedy
class Solution(object):
    def countGroups(self, position, speed, distance):
        """
        :type position: List[int]
        :type speed: List[int]
        :type distance: int
        :rtype: int
        """
        result, s = 0, float("inf")
        for i in reversed(xrange(len(position))):
            if (i+1 < len(position) and position[i+1]-position[i] <= distance) or speed[i] > s:
                continue
            s = speed[i]
            result += 1
        return result


# Time:  O(n)
# Space: O(n)
# mono stack
class Solution2(object):
    def countGroups(self, position, speed, distance):
        """
        :type position: List[int]
        :type speed: List[int]
        :type distance: int
        :rtype: int
        """
        n = len(position)
        stk = []
        for i in xrange(n):
            if i+1 < len(position) and position[i+1]-position[i] <= distance:
                continue
            while stk and stk[-1] > speed[i]:
                stk.pop()
            stk.append(speed[i])
        return len(stk)
