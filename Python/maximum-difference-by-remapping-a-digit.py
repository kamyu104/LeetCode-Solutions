# Time:  O(logn)
# Space: O(1)

# greedy
class Solution(object):
    def minMaxDifference(self, num):
        """
        :type num: int
        :rtype: int
        """
        def f(dst):
            result = 0
            base = 1
            while base <= num:
                base *= 10
            base //= 10
            src = -1
            while base:
                d = num//base%10
                if src == -1 and d != dst:
                    src = d
                result += base*(dst if d == src else d)
                base //= 10
            return result
    
        return f(9)-f(0)
