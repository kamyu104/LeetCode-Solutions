# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minNumberOfFrogs(self, croakOfFrogs):
        """
        :type croakOfFrogs: str
        :rtype: int
        """
        S = "croak"
        lookup = [0]*len(S)
        result = 0
        for c in croakOfFrogs:
            i = S.find(c)
            lookup[i] += 1
            if lookup[i-1]:
                lookup[i-1] -= 1
            elif i == 0:
                result += 1
            else:
                return -1
        return result if result == lookup[-1] else -1
