# Time:  O(n + 24)
# Space: O(24)

# freq table
class Solution(object):
    def countCompleteDayPairs(self, hours):
        """
        :type hours: List[int]
        :rtype: int
        """
        result = 0
        cnt = [0]*24
        for x in hours:
            result += cnt[-x%24]
            cnt[x%24] += 1
        return result


# Time:  O(n^2)
# Space: O(1)
# brute force
class Solution2(object):
    def countCompleteDayPairs(self, hours):
        """
        :type hours: List[int]
        :rtype: int
        """
        return sum((hours[i]+hours[j])%24 == 0 for i in xrange(len(hours)-1) for j in xrange(i+1, len(hours)))
