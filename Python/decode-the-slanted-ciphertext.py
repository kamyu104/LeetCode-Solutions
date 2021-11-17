# Time:  O(n)
# Space: O(1)

class Solution(object):
    def decodeCiphertext(self, encodedText, rows):
        """
        :type encodedText: str
        :type rows: int
        :rtype: str
        """
        cols = len(encodedText)//rows
        k = len(encodedText)
        for i in reversed(xrange(cols)):
            for j in reversed(xrange(i, len(encodedText), cols+1)):
                if encodedText[j] != ' ':
                    k = j
                    break
            else:
                continue
            break
        result = []
        for i in xrange(cols):
            for j in xrange(i, len(encodedText), cols+1):
                result.append(encodedText[j])
                if j == k:
                    break
            else:
                continue
            break
        return "".join(result)


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def decodeCiphertext(self, encodedText, rows):
        """
        :type encodedText: str
        :type rows: int
        :rtype: str
        """
        cols = len(encodedText)//rows
        result = []
        for i in xrange(cols):
            for j in xrange(i, len(encodedText), cols+1):
                result.append(encodedText[j])
        while result and result[-1] == ' ':
            result.pop()
        return "".join(result)

