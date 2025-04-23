# Time:  O(n)
# Space: O(n)

# simulation
class Solution(object):
    def calculateScore(self, instructions, values):
        """
        :type instructions: List[str]
        :type values: List[int]
        :rtype: int
        """
        result = 0
        lookup = [False]*len(instructions)
        i = 0
        while 0 <= i < len(instructions):
            if lookup[i]:
                break
            lookup[i] = True
            if instructions[i] == "add":
                result += values[i]
                i += 1
            else:
                i += values[i]
        return result
