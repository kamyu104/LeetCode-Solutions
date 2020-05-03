# Time:  O(n + l)
# Space: O(l)

class Solution(object):
    def stringShift(self, s, shift):
        """
        :type s: str
        :type shift: List[List[int]]
        :rtype: str
        """
        left_shifts = 0
        for direction, amount in shift:
            if not direction:
                left_shifts += amount
            else:
                left_shifts -= amount
        left_shifts %= len(s)
        return s[left_shifts:] + s[:left_shifts]
