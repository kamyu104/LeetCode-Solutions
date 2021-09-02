# Time:  O(n)
# Space: O(1)

# greedy with two pointers solution
class Solution(object):
    def catchMaximumAmountofPeople(self, team, dist):
        """
        :type team: List[int]
        :type dist: int
        :rtype: int
        """
        result = i = j = 0
        while i < len(team) and j < len(team):
            if i+dist < j or team[i] != 1:
                i += 1
            elif j+dist < i or team[j] != 0:
                j += 1
            else:
                result += 1
                i += 1
                j += 1
        return result


# Time:  O(n)
# Space: O(1)
# greedy with sliding window solution
class Solution2(object):
    def catchMaximumAmountofPeople(self, team, dist):
        """
        :type team: List[int]
        :type dist: int
        :rtype: int
        """
        result = j = 0
        for i in xrange(len(team)):
            if not team[i]:
                continue
            while j < i-dist:
                j += 1
            while j <= min(i+dist, len(team)-1):
                if team[j] == 0:
                    break
                j += 1
            if j <= min(i+dist, len(team)-1):
                result += 1
                j += 1
        return result
