# Time:  O(nlogn)
# Space: O(n)

# ntt, convolution
MOD = 998244353
G = 3

def ntt(a, invert):
    n = len(a)
    j = 0
    for i in xrange(1, n):
        bit = n>>1
        while j & bit:
            j ^= bit
            bit >>= 1
        j ^= bit
        if i < j:
            a[i], a[j] = a[j], a[i]
    length = 2
    while length <= n:
        wlen = pow(G, (MOD-1)//length, MOD)
        if invert:
            wlen = pow(wlen, MOD-2, MOD)
        half = length>>1
        for i in xrange(0, n, length):
            w = 1
            for j in xrange(half):
                u = a[i+j]
                v = a[i+j+half]*w%MOD
                x = u+v
                if x >= MOD:
                    x -= MOD
                y = u-v
                if y < 0:
                    y += MOD
                a[i+j] = x
                a[i+j+half] = y
                w = w*wlen%MOD
        length <<= 1
    if invert:
        inv_n = pow(n, MOD-2, MOD)
        for i in xrange(n):
            a[i] = a[i]*inv_n%MOD


class Solution(object):
    def minOperations(self, s):
        n = len(s)
        sz = 1
        while sz < 2*n-1:
            sz <<= 1
        cost = [0]*n
        for k in xrange(13):
            a = [0]*sz
            cnt = 0
            for i in xrange(n):
                if ((ord(s[i])-ord('a'))-k)%26 >= 13:
                    continue
                a[i] = 1
                cnt += 1
            ntt(a, False)
            for i in xrange(len(a)):
                a[i] = (a[i]*a[i])%MOD
            ntt(a, True)
            for c in xrange(n):
                cost[c] += cnt-(a[c]+(a[c+n] if c+n < len(a) else 0))
        return min(i+cost[(2*i-1)%n] for i in xrange(n))

