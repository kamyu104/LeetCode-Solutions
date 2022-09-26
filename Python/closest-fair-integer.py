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
            left = [0]*2
            for d in digits:
                left[d%2] += 1
            if left[0] == len(digits)//2:
                return n
            for i in reversed(xrange(len(digits)//2, len(digits))):
                left[digits[i]%2] -= 1
                right = [len(digits)//2-left[0], len(digits)//2-left[1]]
                if any(x < 0 for x in right):
                    continue
                d = digits[i]+1 if right[(digits[i]+1)%2]-1 >= 0 else digits[i]+2
                if d > 9:
                    continue
                right[d%2] -= 1
                result = digits[:i]+[d]+[0]*right[0]+[1]*right[1]
                break
        if not result:
            l = len(digits)//2+1
            result = [1]+[0]*l+[1]*(l-1)
        return int("".join(map(str, result)))
