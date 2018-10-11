# Time:  O(n)
# Space: O(1)

class Solution(object):
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        """
        def getNext(S):
            for i in reversed(xrange(len(S))):
                if S[i].isalpha():
                    yield S[i]

        result = []
        letter = getNext(S)
        for i in xrange(len(S)):
            if S[i].isalpha():
                result.append(letter.next())
            else:
                result.append(S[i])
        return "".join(result)

