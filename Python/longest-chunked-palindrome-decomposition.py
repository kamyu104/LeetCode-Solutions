# Time:  O(n)
# Space: O(1)

# Rabin-Karp Algorithm
class Solution(object):
    def __init__(self):
        self.__N = 1000
        self.__MOD = 10**9+7
        self.__D = 26
        self.__pow = [0]*(self.__N+1)
        self.__pow[0] = 1
        for i in xrange(1, len(self.__pow)):
            self.__pow[i] = self.__pow[i-1]*self.__D % self.__MOD
        
    def longestDecomposition(self, text):
        """
        :type text: str
        :rtype: int
        """
        def compare(text, l, s1, s2):
            for i in xrange(l):
                if text[s1+i] != text[s2+i]:
                    return False
            return True

        result = 0
        l, left, right = 0, 0, 0
        for i in xrange(len(text)):
            l += 1
            left = (self.__pow[1]*left + (ord(text[i])-ord('a'))) % self.__MOD
            right = (self.__pow[l-1]*(ord(text[-1-i])-ord('a')) + right) % self.__MOD
            if left == right and compare(text, l, i-l+1, len(text)-1-i):
                result += 1
                l, left, right = 0, 0, 0
        return result
