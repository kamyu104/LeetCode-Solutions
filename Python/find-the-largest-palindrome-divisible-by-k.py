# Time:  O(n)
# Space: O(1)

# constructive algorithms, math
class Solution(object):
    def largestPalindrome(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        def inv(x, p):
            return pow(x, p-2, p)

        def f(l):
            p = 7
            result = ['9']*l
            if l:                
                curr = reduce(lambda accu, x: (accu*10+(ord(x)-ord('0')))%p, result, 0)
                # l%2 == 0: (curr+(i-9)*11*pow(10, l//2-1, p))%p = 0
                # l%2 == 1: (curr+(i-9)*pow(10, l//2, p))%p = 0
                i = 9-(curr*inv(11 if l%2 == 0 else 1, p)*inv(pow(10, l//2-int(l%2 == 0), p), p))%p
                if i <= 2:
                    i += p
                result[l//2] = result[l//2-int(l%2 == 0)] = str(i)
            return "".join(result)

        if k in (1, 3, 9):
            return '9'*n
        if k in (2, 4, 8):
            k = min(k, 6)
            if n <= k:
                return '8'*n
            l = k//2
            return '8'*l+'9'*(n-k)+'8'*l
        if k == 5:
            if n <= 2:
                return '5'*n
            return '5'+'9'*(n-2)+'5'
        if k == 6:
            if n <= 2:
                return '6'*n
            if n%2:
                l = n//2-1
                return '8'+'9'*l+'8'+'9'*l+'8'
            l = n//2-2
            return '8'+'9'*l+"77"+'9'*l+'8'
        l, r = divmod(n, 12)
        return "999999"*l+f(r)+"999999"*l  # 999999%7 = 0
