# Time:  O(n)
# Space: O(1)

# greedy, partition
class Solution(object):
    def maximumOddBinaryNumber(self, s):
        """
        :type s: str
        :rtype: str
        """
        a = list(s)
        left = 0
        for i in xrange(len(a)):
            if a[i] != '1':
                continue
            a[i], a[left] = a[left], a[i]
            left += 1
        if a[-1] != '1':
            a[-1], a[left-1] = a[left-1], a[-1]
        return "".join(a)


# Time:  O(n)
# Space: O(1)
# greedy
class Solution2(object):
    def maximumOddBinaryNumber(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = s.count('1')
        return "".join(['1']*(n-1)+['0']*(len(s)-n)+['1'])
