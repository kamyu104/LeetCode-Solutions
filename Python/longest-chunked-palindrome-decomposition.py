# Time:  O(n)
# Space: O(1)

# Rabin-Karp Algorithm
class Solution(object):
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

        MOD = 10**9+7
        D = 26
        result = 0
        left, right, l, pow_D = 0, 0, 0, 1
        for i in xrange(len(text)):
            left = (D*left + (ord(text[i])-ord('a'))) % MOD
            right = (pow_D*(ord(text[-1-i])-ord('a')) + right) % MOD
            l += 1
            pow_D = (pow_D*D) % MOD 
            if left == right and compare(text, l, i-l+1, len(text)-1-i):
                result += 1
                left, right, l, pow_D = 0, 0, 0, 1
        return result
