# Time:  O(n + m + r)
# Space: O(r)

# line sweep, difference array, greedy
class Solution(object):
    def minSelection(self, availableIntervals, targetIntervals):
        """
        :type availableIntervals: List[List[int]]
        :type targetIntervals: List[List[int]]
        :rtype: int
        """
        diff = [0]*((2*(max(max(r for _, r in availableIntervals), max(r for _, r in targetIntervals))+1)+1))
        for l, r in targetIntervals:
            diff[2*l] += 1
            diff[2*r+1] -= 1
        lookup = [0]*len(diff)
        for l, r in availableIntervals:
            lookup[2*l] = max(lookup[2*l], 2*r)
        result = cnt = reachable = mx = 0
        for i in xrange(len(diff)):
            cnt += diff[i]
            mx = max(mx, lookup[i])
            if not cnt or reachable >= i:
                continue
            if mx < i:
                return -1
            reachable = mx
            result += 1
        return result


# Time:  O(nlogn + mlogm)
# Space: O(1)
# sort, greedy
class Solution2(object):
    def minSelection(self, availableIntervals, targetIntervals):
        """
        :type availableIntervals: List[List[int]]
        :type targetIntervals: List[List[int]]
        :rtype: int
        """
        availableIntervals.sort()
        targetIntervals.sort()
        result = reachable = i = 0
        for l, r in targetIntervals:
            while reachable < r:
                need = max(l, reachable)
                mx = 0
                while i < len(availableIntervals) and availableIntervals[i][0] <= need:
                    mx = max(mx, availableIntervals[i][1])
                    i += 1
                if mx < max(l, reachable+1):
                    return -1
                reachable = mx
                result += 1
        return result
