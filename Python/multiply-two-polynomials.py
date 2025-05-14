# Time:  O((n + m) * log(n + m))
# Space: O(n + m)

import math
import cmath


def fft(a, invert):
    n = len(a)
    if n <= 1:
        return

    # bit-reversal permutation
    j = 0
    for i in xrange(1, n):
        bit = n >> 1
        while j & bit:
            j ^= bit
            bit >>= 1
        j ^= bit
        if i < j:
            a[i], a[j] = a[j], a[i]

    # Cooley-Tukey fft
    length = 2
    while length <= n:
        angle = 2 * math.pi / length * (-1 if invert else 1)
        wlen = complex(math.cos(angle), math.sin(angle))
        for i in xrange(0, n, length):
            w = complex(1)
            for j in xrange(length // 2):
                u = a[i + j]
                v = a[i + j + length // 2] * w
                a[i + j] = u + v
                a[i + j + length // 2] = u - v
                w *= wlen
        length <<= 1

    # divide by n if inverse fft
    if invert:
        for i in xrange(n):
            a[i] /= n


def conv(a, b):
    n, m = len(a), len(b)
    sz, tot = 1, n+m-1
    while sz < tot:
        sz <<= 1
    a = [complex(x, 0) for x in a]+[0]*(sz-n)
    b = [complex(x, 0) for x in b]+[0]*(sz-m)
    fft(a, invert=False)
    fft(b, invert=False)
    for i in xrange(sz):
        a[i] *= b[i]
    fft(a, invert=True)
    return [int(round(a[i].real)) for i in xrange(tot)]


class Solution(object):
    def multiply(self, poly1, poly2):
        """
        :type poly1: List[int]
        :type poly2: List[int]
        :rtype: List[int]
        """
        return conv(poly1, poly2)
