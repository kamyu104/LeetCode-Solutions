# Time:  O(nlogr)
# Space: O(1)

# greedy
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def palindrome(i, l):
            base = 10**((l+1)//2-1)
            rev, x = 0, i
            while x:
                x, r = divmod(x, 10)
                rev = rev*10+r
            return i*(base*10)+rev if l%2 == 0 else i*base+rev%base

        def split(x):
            l = 0
            t = x
            while t:
                t //= 10
                l += 1
            k = (l+1)//2
            h = x//10**(l-k)
            base = 10**(k-1)
            return l, h, base, h//base

        def right(l, h, base, d):
            result = 10**l+1 if x%2 else 2*10**l+2                        # 10..01 / 20..02
            if d%2 != x%2:
                return palindrome((d+1)*base, l) if d+1 <= 9 else result  # (d+1)0..0(d+1)
            p = palindrome(h, l)
            if p >= x:
                return p
            if (h+1)//base == d:
                return palindrome(h+1, l)
            return palindrome((d+2)*base, l) if d+2 <= 9 else result      # (d+2)0..0(d+2)

        def left(l, h, base, d):
            if l == 1:
                result = -1
            elif x%2:
                result = 10**(l-1)-1                                     # 99.99
            else:
                result = palindrome(9*10**(l//2-1)-1, l-1)               # 89..98
            if d%2 != x%2:
                return palindrome(d*base-1, l) if d-1 >= 1 else result   # (d-1)9..9(d-1)
            p = palindrome(h, l)
            if p <= x:
                return p
            if h%base:
                return palindrome(h-1, l)
            return palindrome((d-1)*base-1, l) if d-2 >= 1 else result   # (d-2)9..9(d-2)

        result = 0
        for x in nums:
            l, h, base, d = split(x)
            mn = right(l, h, base, d)-x
            l = left(l, h, base, d)
            if l != -1:
                mn = min(mn, x-l)
            result += mn//2
        return result


# Time:  precompute:  O(sqrt(r)), r = max(nums)
#        runtime:     O(nlogr)
# Space: O(sqrt(r))
# binary search
MAX_L = 10
P = [[] for _ in xrange(2)]
base = 1
for l in xrange(1, MAX_L+1):
    for i in xrange(base, base*10):
        rev, x = 0, i
        while x:
            x, r = divmod(x, 10)
            rev = rev*10+r
        P[rev%2].append(i*(base*10)+rev if l%2 == 0 else i*base+rev%base)
    if l%2 == 0:
        base *= 10
class Solution2(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        INF = float("inf")
        result = 0
        for x in nums:
            i = bisect.bisect_left(P[x%2], x)
            mn = INF
            if i < len(P[x%2]):
                mn = min(mn, P[x%2][i]-x)
            if i-1 >= 0:
                mn = min(mn, x-P[x%2][i-1])
            result += mn//2
        return result
