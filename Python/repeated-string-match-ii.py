# Time:  O(n + m)
# Space: O(n + m)

import itertools


# kmp, Fine and Wilf's Theorem
def gcd(a, b):
    while b:
        a, b = b, a%b
    return a


def getPrefix(pattern):
    prefix = [-1]*len(pattern)
    j = -1
    for i in xrange(1, len(pattern)):
        while j+1 > 0 and pattern[j+1] != pattern[i]:
            j = prefix[j]
        if pattern[j+1] == pattern[i]:
            j += 1
        prefix[i] = j
    return prefix


def KMP(text, pattern):
    prefix = getPrefix(pattern)
    j = -1
    for i, x in enumerate(text):
        while j+1 > 0 and pattern[j+1] != x:
            j = prefix[j]
        if pattern[j+1] == x:
            j += 1
        if j+1 == len(pattern):
            return i-j
    return -1


class Solution(object):
    def repeatedStringMatch(self, a, b, x, y):
        """
        :type a: str
        :type b: str
        :type x: int
        :type y: int
        :rtype: bool
        """
        n, m = len(a), len(b)
        g = gcd(n, m)
        l = min(m*y, n+m-g)
        cnt = min(g if l == n+m-g else n, n*x-m*y+1)
        return KMP(itertools.islice(itertools.cycle(a), l+(cnt-1)), "".join(itertools.islice(itertools.cycle(b), l))) != -1 if cnt-1 >= 0 else False
