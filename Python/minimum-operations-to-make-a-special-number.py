# Time:  O(n)
# Space; O(1)

# math, greedy
class Solution(object):
    def minimumOperations(self, num):
        """
        :type num: str
        :rtype: int
        """
        lookup = [0]*10
        for i in reversed(xrange(len(num))):
            if ((num[i] in "05" and lookup[0]) or
                (num[i] in "27" and lookup[5])):
                return (len(num)-i)-2
            lookup[ord(num[i])-ord('0')] = 1
        return len(num)-lookup[0]
