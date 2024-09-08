# Time:  O(1)
# Space: O(1)

# string
class Solution(object):
    def convertDateToBinary(self, date):
        """
        :type date: str
        :rtype: str
        """
        return "-".join(map(lambda x: bin(int(x))[2:], date.split('-')))
