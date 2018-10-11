# Time:  O(n)
# Space: O(1)

class Solution(object):
    def shiftingLetters(self, S, shifts):
        """
        :type S: str
        :type shifts: List[int]
        :rtype: str
        """
        result = []
        times = sum(shifts) % 26
        for i, c in enumerate(S):
            index = ord(c) - ord('a')
            result.append(chr(ord('a') + (index+times) % 26))
            times = (times-shifts[i]) % 26
        return "".join(result)

