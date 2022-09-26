# Time:  O(logn)
# Space: O(logn)

# constructive algorithms, greedy
class Solution(object):
    def closestFair(self, n):
        """
        :type n: int
        :rtype: int
        """
        digits = map(int, str(n))
        result = []
        if len(digits)%2 == 0:            
            left_even = sum(d%2 == 0 for d in digits)
            if left_even == len(digits)//2:
                return n
            for i in reversed(xrange(len(digits)//2, len(digits))):
                if digits[i]%2 == 0:
                    left_even -= 1
                left_odd = i-left_even
                right_even, right_odd = len(digits)//2-left_even, len(digits)//2-left_odd
                if right_even < 0 or right_odd < 0:
                    continue
                d = digits[i]+2 if (right_odd == 0 and digits[i]%2 == 0) or (right_even == 0 and digits[i]%2 == 1) else digits[i]+1
                if d > 9:
                    continue
                if d%2 == 0:
                    right_even -= 1
                else:
                    right_odd -= 1
                result = digits[:i]+[d]+[0]*right_even+[1]*right_odd
                break
        if not result:
            l = len(digits)//2+1
            result = [1]+[0]*l+[1]*(l-1)
        return int("".join(map(str, result)))
