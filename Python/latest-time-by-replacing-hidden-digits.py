# Time:  O(1)
# Space: O(1)

class Solution(object):
    def maximumTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        result = list(time)
        for i, c in enumerate(time): 
            if c != "?":
                continue
            if i == 0:
                result[i] = '2' if result[i+1] in "?0123" else '1'
            elif i == 1:
                result[i] = '3' if result[0] == '2' else '9'
            elif i == 3:
                result[i] = '5'
            elif i == 4:
                result[i] = '9'
        return "".join(result)
