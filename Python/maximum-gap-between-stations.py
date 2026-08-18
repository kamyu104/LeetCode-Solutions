# Time:  O(n)
# Space: O(n)

# prefix sum, greedy
class Solution(object):
    def maximumGap(self, skill, station):
        """
        :type skill: str
        :type station: str
        :rtype: int
        """
        right = [0]*len(skill)
        j = len(station)-1
        for i in reversed(xrange(len(skill))):
            while station[j] != skill[i]:
                j -= 1
            right[i] = j
            j -= 1
        result = 0
        j = 0
        for i in xrange(len(skill)-1):
            while station[j] != skill[i]:
                j += 1
            result = max(result, right[i+1]-j)
            j += 1
        return result


# Time:  O(n)
# Space: O(n)
# prefix sum, greedy
class Solution2(object):
    def maximumGap(self, skill, station):
        """
        :type skill: str
        :type station: str
        :rtype: int
        """
        left = [0]*len(skill)
        j = 0
        for i in xrange(len(skill)):
            while station[j] != skill[i]:
                j += 1
            left[i] = j
            j += 1
        right = [0]*len(skill)
        j = len(station)-1
        for i in reversed(xrange(len(skill))):
            while station[j] != skill[i]:
                j -= 1
            right[i] = j
            j -= 1
        return max(right[i+1]-left[i] for i in xrange(len(skill)-1)) if len(skill) != 1 else 0
