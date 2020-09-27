# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minOperations(self, logs):
        """
        :type logs: List[str]
        :rtype: int
        """
        result = 0
        for log in logs:
            if log == "../":
                if result > 0:
                    result -= 1
            elif log != "./":
                result += 1
        return result
