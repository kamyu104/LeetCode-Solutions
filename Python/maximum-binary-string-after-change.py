# Time:  O(n)
# Space: O(n)

class Solution(object):
    def maximumBinaryString(self, binary):
        """
        :type binary: str
        :rtype: str
        """
        result = list(binary)
        zeros = ones = 0
        for i, c in enumerate(result):
            if c == '0':
                zeros += 1
            elif zeros == 0:
                ones += 1
            result[i] = '1'
        if ones != len(result):
            result[zeros+ones-1] = '0'
        return "".join(result)
