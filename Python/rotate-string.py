# Time:  O(n)
# Space: O(1)

class Solution(object):
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        def check(index):
            return all(A[(i+index) % len(A)] == c
                       for i, c in enumerate(B))

        if len(A) != len(B):
            return False

        M, p = 10**9+7, 113
        p_inv = pow(p, M-2, M)

        b_hash, power = 0, 1
        for c in B:
            b_hash += power * ord(c)
            b_hash %= M
            power = (power*p) % M

        a_hash, power = 0, 1
        for i in xrange(len(B)):
            a_hash += power * ord(A[i%len(A)])
            a_hash %= M
            power = (power*p) % M

        if a_hash == b_hash and check(0): return True

        power = (power*p_inv) % M
        for i in xrange(len(B), 2*len(A)):
            a_hash = (a_hash-ord(A[(i-len(B))%len(A)])) * p_inv
            a_hash += power * ord(A[i%len(A)])
            a_hash %= M
            if a_hash == b_hash and check(i-len(B)+1):
                return True

        return False


# Time:  O(n)
# Space: O(n)
# KMP algorithm
class Solution2(object):
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        def strStr(haystack, needle):
            def KMP(text, pattern):
                prefix = getPrefix(pattern)
                j = -1
                for i in xrange(len(text)):
                    while j > -1 and pattern[j + 1] != text[i]:
                        j = prefix[j]
                    if pattern[j + 1] == text[i]:
                        j += 1
                    if j == len(pattern) - 1:
                        return i - j
                return -1

            def getPrefix(pattern):
                prefix = [-1] * len(pattern)
                j = -1
                for i in xrange(1, len(pattern)):
                    while j > -1 and pattern[j + 1] != pattern[i]:
                        j = prefix[j]
                    if pattern[j + 1] == pattern[i]:
                        j += 1
                    prefix[i] = j
                return prefix

            if not needle:
                return 0
            return KMP(haystack, needle)

        if len(A) != len(B):
            return False
        return strStr(A*2, B) != -1


# Time:  O(n^2)
# Space: O(n)
class Solution3(object):
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        return len(A) == len(B) and B in A*2

