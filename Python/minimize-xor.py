# Time:  O(logn)
# Space: O(1)

# bit manipulation, greedy
class Solution(object):
    def minimizeXor(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        def popcount(x):
            return bin(x)[2:].count('1')
        
        cnt1, cnt2 = popcount(num1), popcount(num2)
        result = num1
        cnt = abs(cnt1-cnt2)
        expect = 1 if cnt1 >= cnt2 else 0
        i = 0
        while cnt:
            if ((num1>>i)&1) == expect:
                cnt -= 1
                result ^= 1<<i
            i += 1
        return result
