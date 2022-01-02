# Time:  O(m * n)
# Space: O(1)

class Solution(object):
    def numberOfBeams(self, bank):
        """
        :type bank: List[str]
        :rtype: int
        """
        result = prev = 0
        for x in bank:
            cnt = x.count('1')
            if not cnt:
                continue
            result += prev*cnt
            prev = cnt
        return result
