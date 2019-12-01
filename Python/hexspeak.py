# Time:  O(n)
# Space: O(1)

class Solution(object):
    def toHexspeak(self, num):
        """
        :type num: str
        :rtype: str
        """
        lookup = {0:'O', 1:'I'}
        for i in xrange(6):
            lookup[10+i] = chr(ord('A')+i)
        result = []
        n = int(num)
        while n:
            n, r = divmod(n, 16)
            if r not in lookup:
                return "ERROR"
            result.append(lookup[r])
        return "".join(reversed(result))


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def toHexspeak(self, num):
        """
        :type num: str
        :rtype: str
        """
        result = hex(int(num)).upper()[2:].replace('0', 'O').replace('1', 'I')
        return result if all(c in "ABCDEFOI" for c in result) else "ERROR"
