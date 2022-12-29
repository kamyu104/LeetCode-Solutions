# Time:  O(log(min(d1, d2)))
# Space: O(1)

# number theory
class Solution(object):
    def minimizeSet(self, divisor1, divisor2, uniqueCnt1, uniqueCnt2):
        """
        :type divisor1: int
        :type divisor2: int
        :type uniqueCnt1: int
        :type uniqueCnt2: int
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        def lcm(a, b):
            return a//gcd(a, b)*b

        def count(cnt, d1, d2):
            l = lcm(d1, d2)
            return cnt+cnt//(l-1)-int(cnt%(l-1) == 0)
        
        return max(count(uniqueCnt1, divisor1, 1),
                   count(uniqueCnt2, divisor2, 1),
                   count(uniqueCnt1+uniqueCnt2, divisor1, divisor2))


# Time:  O(log(min(d1, d2)) + logr)
# Space: O(1)
# binary search
class Solution2(object):
    def minimizeSet(self, divisor1, divisor2, uniqueCnt1, uniqueCnt2):
        """
        :type divisor1: int
        :type divisor2: int
        :type uniqueCnt1: int
        :type uniqueCnt2: int
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        def lcm(a, b):
            return a//gcd(a, b)*b

        def check(cnt):
            return (cnt-cnt//divisor1 >= uniqueCnt1 and
                    cnt-cnt//divisor2 >= uniqueCnt2 and
                    cnt-cnt//l >= uniqueCnt1+uniqueCnt2)

        l = lcm(divisor1, divisor2)
        left, right = 2, 2**31-1
        while left <= right:
            mid = left+(right-left)//2
            if check(mid):
                right = mid-1
            else:
                left = mid+1
        return left
